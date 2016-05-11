// StringTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../String/MyString.h"

using namespace std;

struct AfterClearFixture
{
	CMyString cleanStr;

	AfterClearFixture()
	{
		cleanStr.Clear();
	}
};

struct AfterMoveFixture
{
	CMyString movedStr;

	AfterMoveFixture() : movedStr("123456")
	{
		CMyString str = std::move(movedStr);
	}
};

void ExpectStringContent(const CMyString& str, const char * arr, size_t len)
{
	BOOST_REQUIRE_EQUAL(str.GetLength(), len);
	BOOST_CHECK_EQUAL(memcmp(str.GetStringData(), arr, len), 0);
}

template <size_t len>
void ExpectStringContent(const CMyString& str, const char (&arr)[len])
{
	ExpectStringContent(str, arr, len);
}

BOOST_AUTO_TEST_SUITE(MyString_tests)

	BOOST_AUTO_TEST_CASE(can_create_string_from_pointer_to_char)
	{
		BOOST_CHECK_THROW(CMyString str(nullptr), std::invalid_argument);
		string example("");
		const char * from = example.c_str();
		BOOST_CHECK_NO_THROW(CMyString str(from));
		CMyString str(from);
		ExpectStringContent(str, from, str.GetLength());
	}

	BOOST_AUTO_TEST_CASE(can_create_string_from_pointer_to_char_with_fixed_length)
	{
		BOOST_CHECK_THROW(CMyString str(nullptr, 17), std::invalid_argument);
		const char * from = "he\0llo";
		BOOST_CHECK_NO_THROW(CMyString str(from, 5));
		CMyString str(from, 6);
		ExpectStringContent(str, from, str.GetLength());
	}

	BOOST_AUTO_TEST_CASE(can_create_string_from_stl_string)
	{
		string example("hello");
		CMyString str(example);
		ExpectStringContent(str, example.c_str(), str.GetLength());
		string example2("hel\0lo", 6);
		CMyString str2(example2);
		ExpectStringContent(str2, example2.c_str(), str2.GetLength());
	}

	BOOST_AUTO_TEST_CASE(have_copy_and_move_contructor)
	{
		CMyString str("hel\0lo");
		CMyString str2(str);
		ExpectStringContent(str, str2.GetStringData(), str.GetLength());
		CMyString str3(std::move(str));
		ExpectStringContent(str, "", 0);
	}

	BOOST_AUTO_TEST_CASE(can_get_substring_from_string)
	{
		CMyString str("hel\0lo");
		auto newStr = str.SubString(1);
		auto newStr2 = str.SubString(0, 0);
		BOOST_CHECK_THROW(str.SubString(10, 1), std::out_of_range);
		ExpectStringContent("el", newStr.GetStringData(), newStr.GetLength());
		ExpectStringContent("", newStr2.GetStringData(), newStr2.GetLength());
	}

	BOOST_AUTO_TEST_CASE(can_clear_string)
	{
		CMyString str("hel\0lo");
		str.Clear();
		ExpectStringContent("", str.GetStringData(), 0);
	}

	BOOST_AUTO_TEST_CASE(has_comparison_operator)
	{
		CMyString str1("123");
		CMyString empty("");
		BOOST_CHECK_EQUAL(str1 == "123", true);
		BOOST_CHECK_EQUAL(str1 != "123", false);
		BOOST_CHECK_EQUAL(str1 == "124", false);
		BOOST_CHECK_EQUAL(str1 != "124", true);
		BOOST_CHECK_EQUAL(empty == "", true);
		BOOST_CHECK_EQUAL(empty != "", false);
		BOOST_CHECK_EQUAL(empty == "1", false);
		BOOST_CHECK_EQUAL(empty != "1", true);
	}

	BOOST_AUTO_TEST_CASE(has_assignment_with_move_operator)
	{
		CMyString str1("123");
		CMyString str2("321");
		str1 = std::move(str2);
		ExpectStringContent(str1.GetStringData(), "321", 3);
		ExpectStringContent(str2.GetStringData(), "", 0);
		CMyString tmp(str1);
		str1 = std::move(str1);
		ExpectStringContent(str1.GetStringData(), tmp.GetStringData(), str1.GetLength());		
	}

	BOOST_AUTO_TEST_CASE(has_assignment_operator)
	{
		CMyString str1;
		str1 = "123";
		ExpectStringContent(str1.GetStringData(), "123", 3);
		CMyString tmp(str1);
		str1 = str1;
		ExpectStringContent(str1.GetStringData(), tmp.GetStringData(), str1.GetLength());
	}

	BOOST_AUTO_TEST_CASE(has_concatenation_with_assignment_operator)
	{
		auto sumWithMyString = CMyString();
		sumWithMyString += CMyString("1");
		auto sumWithMyString2 = CMyString("1");
		sumWithMyString2 += CMyString();
		auto sumWithMyString3 = CMyString("1");
		sumWithMyString3 += CMyString("2");
		auto sumWithMyString4 = CMyString();
		sumWithMyString4 += CMyString();

		ExpectStringContent(sumWithMyString.GetStringData(), "1", 1);
		ExpectStringContent(sumWithMyString2.GetStringData(), "1", 1);
		ExpectStringContent(sumWithMyString3.GetStringData(), "12", 2);
		ExpectStringContent(sumWithMyString4.GetStringData(), "", 0);
	}

	BOOST_AUTO_TEST_CASE(has_lexicographical_comparison_operators)
	{
		BOOST_CHECK_EQUAL(CMyString("123") < "1234", true);
		BOOST_CHECK_EQUAL(CMyString("123") > "1234", false);
		BOOST_CHECK_EQUAL(CMyString("123") > "123", false);
		BOOST_CHECK_EQUAL(CMyString("123") < "123", false);

		BOOST_CHECK_EQUAL(CMyString("123") <= "123", true);
		BOOST_CHECK_EQUAL(CMyString("123") >= "123", true);
		BOOST_CHECK_EQUAL(CMyString("123") >= "1234", false);
		BOOST_CHECK_EQUAL(CMyString("123") <= "1234", true);
	}

	BOOST_AUTO_TEST_CASE(has_indexed_acces_operators)
	{
		CMyString str("123");
		BOOST_CHECK(str[1] == '2');
		BOOST_CHECK(str[3] == '\0');
		str = "";
		BOOST_CHECK(str[0] == '\0');
	}

	BOOST_AUTO_TEST_CASE(has_stream_extraction_and_insertion_operators)
	{
		std::ostringstream oss;
		oss << CMyString("123");
		BOOST_CHECK_EQUAL(oss.str(), "123");
		oss << CMyString();
		BOOST_CHECK_EQUAL(oss.str(), "123");
		oss << CMyString("1\0");
		BOOST_CHECK_EQUAL(oss.str(), "1231");

		std::istringstream iss("12345");
		auto str = CMyString();
		iss >> str;
		BOOST_CHECK_EQUAL(str, "12345");
		iss = std::istringstream("654321");
		iss >> str;
		BOOST_CHECK_EQUAL(str, "654321");

	}

	BOOST_AUTO_TEST_CASE(has_concatenation_operator)
	{
		auto sumWithMyString = CMyString() + CMyString("1");
		auto sumWithMyString2 = CMyString("1") + CMyString();
		auto sumWithMyString3 = CMyString("1") + CMyString("2");
		auto sumWithMyString4 = CMyString() + CMyString();

		ExpectStringContent(sumWithMyString, "1", 1);
		ExpectStringContent(sumWithMyString2, "1", 1);
		ExpectStringContent(sumWithMyString3, "12", 2);
		ExpectStringContent(sumWithMyString4, "", 0);
	}

	BOOST_AUTO_TEST_CASE(has_concatenation_with_stl_string_operator)
	{
		auto sumWithStlString = std::string("1") + CMyString();
		auto sumWithStlString2 = std::string("") + CMyString("1");
		auto sumWithStlString3 = std::string("1") + CMyString("2");
		auto sumWithStlString4 = std::string() + CMyString();

		ExpectStringContent(sumWithStlString, "1", 1);
		ExpectStringContent(sumWithStlString2, "1", 1);
		ExpectStringContent(sumWithStlString3, "12", 2);
		ExpectStringContent(sumWithStlString4, "", 0);
	}

	BOOST_AUTO_TEST_CASE(has_concatenation_with_char_string_operator)
	{
		const char * ptrString = new char[2]{ '1', '\0' };
		const char * ptrString2 = new char[1]{ '\0' };

		auto sumWithCharArrayString = ptrString + CMyString();
		auto sumWithCharArrayString2 = ptrString + CMyString("2");
		auto sumWithCharArrayString3 = ptrString2 + CMyString("1");
		auto sumWithCharArrayString4 = ptrString2 + CMyString();

		ExpectStringContent(sumWithCharArrayString, "1", 1);
		ExpectStringContent(sumWithCharArrayString2, "12", 2);
		ExpectStringContent(sumWithCharArrayString3, "1", 1);
		ExpectStringContent(sumWithCharArrayString4, "", 0);

		delete[] ptrString;
		delete[] ptrString2;
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(after_clearing_string, AfterClearFixture)

BOOST_AUTO_TEST_CASE(can_get_substring)
{
	BOOST_CHECK(CMyString("") == cleanStr.SubString(0, 5));
}

BOOST_AUTO_TEST_CASE(method_begin_get_iterator_equal_to_end)
{
	BOOST_CHECK(cleanStr.begin() == cleanStr.end());
}

BOOST_AUTO_TEST_CASE(can_use_copy_assignment)
{
	cleanStr = CMyString("123");
	BOOST_CHECK(cleanStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_use_move_assignment)
{
	cleanStr = std::move(CMyString("123"));
	BOOST_CHECK(cleanStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_be_used_in_copy_assignment)
{
	auto str = cleanStr;
	BOOST_CHECK(str == cleanStr);
}

BOOST_AUTO_TEST_CASE(can_be_used_in_move_assignment)
{
	auto str = std::move(cleanStr);
	BOOST_CHECK(cleanStr == CMyString(""));
}

BOOST_AUTO_TEST_CASE(can_concatenate_with_assignment)
{
	cleanStr += CMyString("123");
	BOOST_CHECK(cleanStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_be_used_in_concatenate_with_assignment)
{
	CMyString str("123");
	str += cleanStr;
	BOOST_CHECK(str == CMyString("123"));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(after_moving_string, AfterMoveFixture)

BOOST_AUTO_TEST_CASE(can_get_substring)
{
	BOOST_CHECK(CMyString("") == movedStr.SubString(0, 5));
}

BOOST_AUTO_TEST_CASE(method_begin_get_iterator_equal_to_end)
{
	BOOST_CHECK(movedStr.begin() == movedStr.end());
}

BOOST_AUTO_TEST_CASE(can_use_copy_assignment)
{
	movedStr = CMyString("123");
	BOOST_CHECK(movedStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_use_move_assignment)
{
	movedStr = std::move(CMyString("123"));
	BOOST_CHECK(movedStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_be_used_in_copy_assignment)
{
	auto str = movedStr;
	BOOST_CHECK(str == movedStr);
}

BOOST_AUTO_TEST_CASE(can_be_used_in_move_assignment)
{
	auto str = std::move(movedStr);
	BOOST_CHECK(movedStr == CMyString(""));
}

BOOST_AUTO_TEST_CASE(can_concatenate_with_assignment)
{
	movedStr += CMyString("123");
	BOOST_CHECK(movedStr == CMyString("123"));
}

BOOST_AUTO_TEST_CASE(can_be_used_in_concatenate_with_assignment)
{
	CMyString str("123");
	str += movedStr;
	BOOST_CHECK(str == CMyString("123"));
}

BOOST_AUTO_TEST_SUITE_END()
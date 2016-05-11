#include "stdafx.h"
#include "../String/MyString.h"
#include "../String/StringIterator.h"

struct StringFixture
{
	CMyString str = "123456";
	const CMyString const_str = "123456";
};

BOOST_FIXTURE_TEST_SUITE(Iterator_tests, StringFixture)

BOOST_AUTO_TEST_CASE(can_get_iterator_to_string_begin)
{
	BOOST_CHECK_EQUAL(*str.begin(), str[0]);
}

BOOST_AUTO_TEST_CASE(can_get_iterator_to_string_end)
{
	BOOST_CHECK_EQUAL(*str.end(), str[str.GetLength()]);
}

BOOST_AUTO_TEST_CASE(can_create_from_ptr)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	BOOST_CHECK_EQUAL(*it, *numPtr);
}

BOOST_AUTO_TEST_CASE(has_copy_constructor)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	auto it2 = it;
	BOOST_CHECK_EQUAL(*it, *it2);
}

BOOST_AUTO_TEST_CASE(has_operators_for_checking_equality)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	CStringIterator<char> it2(numPtr);
	BOOST_CHECK(it == it2);
	it = CStringIterator<char>(numPtr + 1);
	BOOST_CHECK(it != it2);
}

BOOST_AUTO_TEST_CASE(has_prefix_increment_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	BOOST_CHECK(++it != numPtr);
	BOOST_CHECK(++it == numPtr + 2);
	BOOST_CHECK(++it == numPtr + 3);
}

BOOST_AUTO_TEST_CASE(has_prefix_decrement_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	++it;
	++it;
	BOOST_CHECK(--it == numPtr + 1);
	BOOST_CHECK(--it == numPtr);
}

BOOST_AUTO_TEST_CASE(has_postfix_increment_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	BOOST_CHECK(it++ == numPtr);
	BOOST_CHECK(it++ == numPtr + 1);
	BOOST_CHECK(it++ == numPtr + 2);
}

BOOST_AUTO_TEST_CASE(has_postfix_decrement_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	++it;
	++it;
	BOOST_CHECK(it-- == numPtr + 2);
	BOOST_CHECK(it-- == numPtr + 1);
}

BOOST_AUTO_TEST_CASE(have_add_with_assignment_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	BOOST_CHECK(*(it += 3) == *(numPtr + 3));
	BOOST_CHECK(*(it += 1) == *(numPtr + 4));
	BOOST_CHECK(*(it += 2) == *(numPtr + 6));
}

BOOST_AUTO_TEST_CASE(have_substract_with_assignment_operator)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	it += 3;
	BOOST_CHECK(*(it -= 1) == *(numPtr + +2));
	BOOST_CHECK(*(it -= 2) == *numPtr);
}

BOOST_AUTO_TEST_CASE(can_substract_one_iterator_from_another)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	CStringIterator<char> it2(numPtr + 3);
	BOOST_CHECK(it - it2 == 0);
	BOOST_CHECK(it2 - it == 3);
	BOOST_CHECK(it - it == 0);
}

BOOST_AUTO_TEST_CASE(can_add_digit_to_iterator_and_vice_versa)
{
	char * numPtr = &str[0];
	CStringIterator<char> it(numPtr);
	CStringIterator<char> it2(numPtr + 3);
	BOOST_CHECK(it + 3  == numPtr + 3);
	BOOST_CHECK(it + 2 == numPtr + 2);
	BOOST_CHECK(3 + it == numPtr + 3);
}

BOOST_AUTO_TEST_CASE(has_random_access_operator)
{
	char * numPtr = &str[0];
	auto it = str.begin();
	BOOST_CHECK(it[0] == *str.begin());
	BOOST_CHECK(it[3] == *(str.begin() + 3));
	BOOST_CHECK(it[5] == *(str.begin() + 5));

}

BOOST_AUTO_TEST_CASE(can_get_reverse_iterator_to_rbegin_and_rend)
{
	BOOST_CHECK(str.rbegin() == str.end());
	BOOST_CHECK(str.rend() == str.begin());
}

BOOST_AUTO_TEST_CASE(iterator_can_iterate_from_begin_to_end)
{
	char * numPtr = &str[0];
	size_t counter = 0;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		BOOST_CHECK(*it == *(numPtr + counter));
		counter++;
	}

}

BOOST_AUTO_TEST_CASE(reverse_iterator_iterate_from_end_to_begin)
{
	char * numPtr = &str[0];
	size_t counter = 6;
	for (auto it = str.rbegin(); it != str.rend(); ++it)
	{
		BOOST_CHECK(*it == *(numPtr + counter));
		counter--;
	}

}

BOOST_AUTO_TEST_CASE(supports_iteration_through_range_based_for)
{
	char * numPtr = &str[0];
	size_t counter = 0;
	for (auto & it : str)
	{
		BOOST_CHECK(it == str[counter]);
		counter++;
	}
}


BOOST_AUTO_TEST_SUITE_END()

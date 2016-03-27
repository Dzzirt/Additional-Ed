// DictionaryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Dictionary/Dictionary.h"
#include "../Dictionary/TempDir.h"
using namespace std;

struct NoneEmptyDictionaryFixture
{
	CTempDir tempDir;	
	DictionaryLogic logic = DictionaryLogic(tempDir.MakeCopyOfFile("../DictionaryTest/nonEmptyTestDict.txt"));
	DictionaryUI ui;
	Dictionary dict = Dictionary(logic, ui);
};

BOOST_FIXTURE_TEST_SUITE(DictionaryTest, NoneEmptyDictionaryFixture)

	BOOST_AUTO_TEST_CASE(Can_read_dictionary_from_file)
	{
		auto dictionary = logic.GetMapFromFile();

		map<string, string> expectedDict {
			{"Teddy Bear", "Плюшевый мишка" },
			{"Sponge Bob", "Спанч Боб"},
			{"Rabbit", "Кролик"}
		};
		BOOST_CHECK(dictionary == expectedDict);
	}

	BOOST_AUTO_TEST_CASE(Can_answer_a_word_in_the_dictionary_or_not)
	{
		BOOST_CHECK(logic.HasWord("Teddy Bear"));
		BOOST_CHECK(!logic.HasWord("Car")); 
	}

	BOOST_AUTO_TEST_CASE(Can_insert_new_pairs_in_dictionary)
	{
		logic.InsertPair("Hope", "Надежда");
		BOOST_CHECK(logic.HasWord("Hope"));
	}

	BOOST_AUTO_TEST_CASE(Can_save_new_pairs_in_file)
	{
		logic.InsertPair("Hope", "Надежда");
		auto dictionary = logic.GetMapFromFile();
		map<string, string> expectedDict{
			{ "Teddy Bear", "Плюшевый мишка" },
			{ "Sponge Bob", "Спанч Боб" },
			{ "Rabbit", "Кролик" },
			{ "Hope", "Надежда"}
		};
		BOOST_CHECK(dictionary != expectedDict);
		logic.SaveNewWordsInFile();
		dictionary = logic.GetMapFromFile();
		BOOST_CHECK(dictionary == expectedDict);
	}



	BOOST_AUTO_TEST_CASE(Returns_translation_of_input_word)
	{
		logic.InsertPair("Hope", "Надежда");
		BOOST_CHECK_EQUAL(logic.GetValueAt("Hope"), "Надежда");
		BOOST_CHECK_EQUAL(logic.GetValueAt("Car"), "");
	}
BOOST_AUTO_TEST_SUITE_END();
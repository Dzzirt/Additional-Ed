#include "stdafx.h"
#include "../StringList/StringListIterator.h"

using namespace std;

struct EmptyStringList
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(String_list, EmptyStringList)

	BOOST_AUTO_TEST_CASE(can_construct_from_initializer_list)
	{
		list = {"1", "2", "3"};
		BOOST_CHECK_EQUAL(*list.begin(), "1");
		BOOST_CHECK_EQUAL(*(++list.begin()), "2");
		auto it = list.begin();
		it++; it++;
		BOOST_CHECK_EQUAL(*it, "3");
	}

    BOOST_AUTO_TEST_SUITE(has)
        BOOST_AUTO_TEST_CASE(begin_and_end_methods_that_returns_iterators)
        {
            list = {"1", "2", "3"};
            BOOST_CHECK(*list.begin() == "1");
            auto beforeEnd = list.begin();
            std::advance(beforeEnd, list.GetSize() - 1);
			BOOST_CHECK(--list.end() == beforeEnd);
            BOOST_CHECK(list.end() == ++beforeEnd);


			list = {};
			BOOST_CHECK(list.end() == list.begin());
        }


        BOOST_AUTO_TEST_CASE(rbegin_and_rend_methods_that_returns_iterators)
        {
            list = {"1", "2", "3"};
            auto beforeEnd = list.begin();
            std::advance(beforeEnd, list.GetSize() - 1);
            BOOST_CHECK(list.rbegin() == beforeEnd);

			BOOST_CHECK(list.rend() == --list.begin());
			BOOST_CHECK(--list.rend() == list.begin());
			BOOST_CHECK(list.end() == --list.rbegin());

			list = {};
			BOOST_CHECK(list.rend() == list.rbegin());


        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE(after_erase)
	    BOOST_AUTO_TEST_CASE(return_iterator_to_next_element)
		{
            //Erasing from middle
			list = {"0", "1", "2", "3"};
			auto it = list.begin();
			std::advance(it, 2);
			it = list.Erase(it);

			BOOST_CHECK(addressof(*it) == addressof(*list.rbegin()));
			BOOST_CHECK(addressof(*--it) == addressof(*++list.begin()));

            //Erasing from begin
			it = list.begin();
			it = list.Erase(it);
			BOOST_CHECK(addressof(*it) == addressof(*list.begin()));
			BOOST_CHECK(addressof(*++it) == addressof(*++list.begin()));

            //Erasing from end

            it = list.rbegin();
            it = list.Erase(it);
            BOOST_CHECK(it == list.end());

			//Erasing from list with 1 element
			list = {"1"};
			auto pos = list.begin();
			pos = list.Erase(pos);
			BOOST_CHECK(pos == list.end());
			BOOST_CHECK(list.IsEmpty());

		}
		BOOST_AUTO_TEST_CASE(decrease_size_by_1)
		{
			list = {"0", "1", "2", "3"};
			auto it = list.begin();
			std::advance(it, 2);
			auto size = list.GetSize();
			it = list.Erase(it);
			BOOST_CHECK(list.GetSize() == size - 1);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(list.GetSize(), 0u);
			BOOST_CHECK_EQUAL(list.IsEmpty(), true);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_appeding_a_string)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetBackElement_method)
		{
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "hello");
			list.Append("goodbye");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_last_element)
		{
			list.Append("hello");
			list.Append("hello1");
			list.Append("hello2");
			BOOST_CHECK_EQUAL(addressof(*list.rbegin()), addressof(list.GetBackElement()));

		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_pushing_front_a_string)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.PushFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.PushFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetFrontElement_method)
		{
			list.PushFront("hello");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "hello");
			list.PushFront("goodbye");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
		{
			list.PushFront("hello");
			list.PushFront("hello2");
			list.PushFront("hello3");
			list.PushFront("hello4");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetFrontElement()));
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(after_clearing)
		BOOST_AUTO_TEST_CASE(list_is_empty)
		{
			list = {"1", "2", "3", "4"};
			list.Clear();
			BOOST_CHECK(list.IsEmpty());
			BOOST_CHECK(list.begin() == list.end());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(iterator)

        BOOST_AUTO_TEST_SUITE(has)
            BOOST_AUTO_TEST_CASE(compare_operators)
            {
                list = {"1", "3"};
				CStringListIterator it1 = CStringListIterator(list.begin());
				CStringListIterator it2 = CStringListIterator(list.begin());
                BOOST_CHECK(it1 == it2);
                it2 = CStringListIterator(list.rbegin());
                BOOST_CHECK(it1 != it2);
            }
            BOOST_AUTO_TEST_CASE(substract_with_assignment_operators)
            {
                list = {"1", "3"};
				CStringListIterator it1 = CStringListIterator(list.rbegin());
                BOOST_CHECK(*(++it1) == "1");
                it1--;
                BOOST_CHECK(*(it1++) == "3");
            }
        BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(can_iterate)
			BOOST_AUTO_TEST_CASE(through_range_based_for)
			{
				list = {"1", "2", "3"};
				std::vector<std::string> vector1 = {"1", "2", "3"};
				size_t counter = 0;
				for (auto const& str : list)
				{
					BOOST_CHECK(str == vector1[counter]);
					counter++;
				}
			}

			BOOST_AUTO_TEST_CASE(forward_and_reverse)
			{
				list = {"1", "2", "3"};
				std::vector<std::string> vector1 = {"1", "2", "3"};
				size_t counter = 0;
				for (auto it = list.begin(); it != list.end(); ++it)
				{
					BOOST_CHECK(*it == vector1[counter]);
					counter++;
				}

				for (auto it = list.rbegin(); it != list.rend(); ++it)
				{
					BOOST_CHECK(*it == vector1[counter - 1]);
					counter--;
				}
			}
		BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
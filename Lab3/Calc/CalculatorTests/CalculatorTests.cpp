#include "stdafx.h"
#include "../Calculator/Calculator.h"

using namespace std;

struct CalcFixture
{
    Calculator calculator;
};

struct with_one_var : public CalcFixture
{
    with_one_var()
    {
        BOOST_REQUIRE_NO_THROW(calculator.AddVariable("id"));
        BOOST_REQUIRE_NO_THROW(calculator.AssignVariableValue("id", "3.33"));
    }
};
struct after_creating_some_identifiers : public CalcFixture
{
    after_creating_some_identifiers()
    {
        BOOST_REQUIRE_NO_THROW(calculator.AddVariable("var1"));
        BOOST_REQUIRE_NO_THROW(calculator.AddVariable("var2"));
        BOOST_REQUIRE_NO_THROW(calculator.AssignVariableValue("var1", "2.7869"));
        BOOST_REQUIRE_NO_THROW(calculator.AssignVariableValue("var2", "2.7869"));


        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func1", "var1+var2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func2", "var1-var2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func3", "var1*var2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func4", "var1/var2"));

        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func5", "func1+func2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func6", "func1-func2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func7", "func1*func2"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func8", "func1/func2"));

        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func9", "var1"));
        BOOST_REQUIRE_NO_THROW(calculator.AddFunction("func10", "func1"));
    }
};
BOOST_FIXTURE_TEST_SUITE(Calculator_tests, CalcFixture)

    BOOST_FIXTURE_TEST_SUITE(during_identifier_creation, with_one_var)
        BOOST_AUTO_TEST_CASE(throws_error_if_variable_name_has_incorrect_format)
        {
            BOOST_CHECK_THROW(calculator.AddVariable("1id"), invalid_argument);
            BOOST_CHECK_THROW(calculator.AddVariable("i$d"), invalid_argument);
            BOOST_CHECK_NO_THROW(calculator.AddVariable("id1"));
            BOOST_CHECK_NO_THROW(calculator.AddVariable("id9"));
            BOOST_CHECK_NO_THROW(calculator.AddVariable("i9d9"));
            BOOST_CHECK_NO_THROW(calculator.AddVariable("_i9d9_"));

        }
        BOOST_AUTO_TEST_CASE(throws_error_if_function_name_has_incorrect_format)
        {
            BOOST_CHECK_THROW(calculator.AddFunction("1id", ""), invalid_argument);
            BOOST_CHECK_THROW(calculator.AddFunction("i$d", ""), invalid_argument);
            BOOST_CHECK_NO_THROW(calculator.AddFunction("id1", "id"));
            BOOST_CHECK_NO_THROW(calculator.AddFunction("id9", "id"));
            BOOST_CHECK_NO_THROW(calculator.AddFunction("i9d9", "id"));
            BOOST_CHECK_NO_THROW(calculator.AddFunction("_i9d9_", "id"));
        }
        BOOST_AUTO_TEST_CASE(throws_error_if_identifier_is_already_declared)
        {
            BOOST_CHECK_THROW(calculator.AddVariable("id"), invalid_argument);
            BOOST_CHECK_THROW(calculator.AddFunction("id", ""), invalid_argument);
        }
        BOOST_AUTO_TEST_CASE(throw_error_if_value_is_not_declared)
        {
            calculator.AddVariable("go");
            BOOST_CHECK_THROW(calculator.AssignVariableValue("go", "undeclared"), invalid_argument);
            BOOST_CHECK_THROW(calculator.AddFunction("went", "undeclared2"), invalid_argument);
        }
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_FIXTURE_TEST_SUITE(after_creating, after_creating_some_identifiers)
        BOOST_AUTO_TEST_CASE(can_print_function)
        {
            BOOST_CHECK(calculator.GetDoubleValue("func1") == 5.5738000000000003);
            BOOST_CHECK(calculator.GetDoubleValue("func2") == 0);
            BOOST_CHECK(calculator.GetDoubleValue("func3") == 7.76681161);
            BOOST_CHECK(calculator.GetDoubleValue("func4") == 1);

            BOOST_CHECK(calculator.GetDoubleValue("func5") == 5.5738000000000003);
            BOOST_CHECK(calculator.GetDoubleValue("func6") == 5.5738000000000003);
            BOOST_CHECK(calculator.GetDoubleValue("func7") == 0);
            BOOST_CHECK(calculator.GetDoubleValue("func8") == std::numeric_limits<double>::infinity());
            BOOST_CHECK(calculator.GetDoubleValue("func9") == 2.7869);
            BOOST_CHECK(calculator.GetDoubleValue("func10") == 5.5738000000000003);
        }
        BOOST_AUTO_TEST_CASE(can_print_variable)
        {
            BOOST_CHECK(calculator.GetDoubleValue("var1") == 2.7869);
            BOOST_CHECK(calculator.GetDoubleValue("var2") == 2.7869);
        }
        BOOST_AUTO_TEST_CASE(function_stores_data_by_reference)
        {
            BOOST_CHECK(calculator.GetDoubleValue("func1") == 5.5738);
            calculator.AssignVariableValue("var2", "1");
            BOOST_CHECK(calculator.GetDoubleValue("func1") == 3.7869);
        }
        BOOST_AUTO_TEST_CASE(variables_stores_data_by_value)
        {
            BOOST_CHECK(calculator.GetDoubleValue("var1") == 2.7869);
            calculator.AddVariable("var3");
            calculator.AssignVariableValue("var3", "var1");
            calculator.AssignVariableValue("var1", "5");
            BOOST_CHECK(calculator.GetDoubleValue("var3") == 2.7869);
        }
        BOOST_AUTO_TEST_CASE(cannot_reassign_function)
        {
            BOOST_CHECK_THROW(calculator.AssignVariableValue("func1", "var1"), invalid_argument);
        }
    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
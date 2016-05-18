// Protocol::HTTPUrlTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../HttpUrl/HttpUrl.h"
#include "../HttpUrl/UrlParsingError.h"


BOOST_AUTO_TEST_SUITE(after_passing_url_to_constructor_as_string)

	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_url_is_empty)
	{
		BOOST_CHECK_THROW(CHttpUrl url(""), CUrlParsingError);
	}

	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_protocol_is_incorrect)
	{
		BOOST_CHECK_THROW(CHttpUrl url("ftp://"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("html://"), CUrlParsingError);
		BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com/abc.jpeg"));
		BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com/abc.jpeg"));
	}
	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_incorrect_format_after_protocol)
	{
		BOOST_CHECK_THROW(CHttpUrl url("http::/"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("http::///"), CUrlParsingError);
		BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com/abc.jpeg"));
		BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com"));
		CHttpUrl url("https://game.com");
		BOOST_CHECK(url.GetDocument() == "/");
		
	}
	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_domain_is_empty_or_contains_whitespaces)
	{
		BOOST_CHECK_THROW(CHttpUrl url("http://ga me .com"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("http:///abc.jpeg"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("http://		s"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("http://"), CUrlParsingError);
		BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com"));
		BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com/abc.jpeg"));
	}
	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_port_more_than_65535_or_have_non_numeric_value)
	{
		BOOST_CHECK_NO_THROW(CHttpUrl url("http://game.com:0"));
		BOOST_CHECK_NO_THROW(CHttpUrl url("https://game.com:65534"));
		BOOST_CHECK_THROW(CHttpUrl url("http://game.com:dfsf"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("https://game.com:65f545"), CUrlParsingError);
		BOOST_CHECK_THROW(CHttpUrl url("https://game.com:65545"), CUrlParsingError);
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(after_passing_url_parameters_manually)

	BOOST_AUTO_TEST_CASE(throws_parsing_error_if_domain_is_empty_or_contains_whitespaces)
	{
		BOOST_CHECK_THROW(CHttpUrl url("", "/asd.jpeg", Protocol::HTTPS, 789), std::invalid_argument);
		BOOST_CHECK_NO_THROW(CHttpUrl url("ispring.com", "/asd.jpeg", Protocol::HTTPS, 789));
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(after_initializing)

	BOOST_AUTO_TEST_CASE(can_get_each_part_of_url)
	{
		CHttpUrl url("http://game.com:12345/abc.jpeg");
		BOOST_CHECK_EQUAL(static_cast<int>(url.GetProtocol()), static_cast<int>(Protocol::HTTP));
		BOOST_CHECK_EQUAL(url.GetDomain(), "game.com");
		BOOST_CHECK_EQUAL(url.GetPort(), 12345);
		BOOST_CHECK_EQUAL(url.GetDocument(), "/abc.jpeg");
		BOOST_CHECK_EQUAL(url.GetURL(), "http://game.com:12345/abc.jpeg");

		CHttpUrl url2("katewinslet.com", "/cats", Protocol::HTTPS, 666);
		BOOST_CHECK(url2.GetProtocol() != Protocol::HTTP);
		BOOST_CHECK(url2.GetDomain() != "gasme.com");
		BOOST_CHECK(url2.GetPort() != 1234);
		BOOST_CHECK(url2.GetDocument() != "/abc.jpeg");
		BOOST_CHECK_EQUAL(url2.GetURL(), "https://katewinslet.com:666/cats");
	}

	BOOST_AUTO_TEST_CASE(document_can_be_any)
	{
		BOOST_CHECK_NO_THROW(CHttpUrl url1("katewinslet.com", "cats", Protocol::HTTPS, 666));
		BOOST_CHECK_NO_THROW(CHttpUrl url2("https://kek.com/lol/nya/kok"));
		BOOST_CHECK_NO_THROW(CHttpUrl url3("katewinslet.com", "", Protocol::HTTPS, 666));
		BOOST_CHECK_NO_THROW(CHttpUrl url4("https://kek.com"));
	}

	BOOST_AUTO_TEST_CASE(adds_forward_slash_if_document_havent_it)
	{
		CHttpUrl url2("katewinslet.com", "cats", Protocol::HTTPS, 666);
		BOOST_CHECK(url2.GetDocument() == "/cats");
		CHttpUrl url3("katewinslet.com", "/cats", Protocol::HTTPS, 666);
		BOOST_CHECK(url3.GetDocument() == "/cats");
	}

	BOOST_AUTO_TEST_CASE(default_ports_not_including_in_GetURL)
	{
		CHttpUrl url1("https://game.com:443/");
		CHttpUrl url2("http://game.com:80/abc.jpeg/asd/asfds/gdfgd");
		BOOST_CHECK_EQUAL(url1.GetURL(), "https://game.com/");
		BOOST_CHECK_EQUAL(url2.GetURL(), "http://game.com/abc.jpeg/asd/asfds/gdfgd");
	}

	BOOST_AUTO_TEST_CASE(can_get_full_url_after_parsing)
	{
		CHttpUrl url1("http://game.com/abc.jpeg");
		CHttpUrl url2("http://game.com:12345");
		CHttpUrl url3("http://game.com");
		CHttpUrl url4("http://game.com:12345/abc.jpeg///////");
		CHttpUrl url5("http://game.com/abc.jpeg/asd/asfds/gdfgd");
		BOOST_CHECK_EQUAL(url1.GetURL(), "http://game.com/abc.jpeg");
		BOOST_CHECK_EQUAL(url2.GetURL(), "http://game.com:12345/");
		BOOST_CHECK_EQUAL(url3.GetURL(), "http://game.com/");
		BOOST_CHECK_EQUAL(url4.GetURL(), "http://game.com:12345/abc.jpeg///////");
		BOOST_CHECK_EQUAL(url5.GetURL(), "http://game.com/abc.jpeg/asd/asfds/gdfgd");
	}
BOOST_AUTO_TEST_SUITE_END()
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define BOOST_TEST_INCLUDED
#ifdef _WIN32
#pragma warning (disable: 4702)
#pragma warning (disable: 4535)
#endif
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/replace.hpp>

// TODO: reference additional headers your program requires here

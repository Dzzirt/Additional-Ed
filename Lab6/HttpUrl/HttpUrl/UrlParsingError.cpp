#include "stdafx.h"
#include "UrlParsingError.h"

CUrlParsingError::CUrlParsingError(std::string const& what_arg)
	:invalid_argument(what_arg)
{

}


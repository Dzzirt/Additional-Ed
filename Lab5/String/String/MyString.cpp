#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
{
}


CMyString::CMyString(const char * pString, size_t length)
{

}

CMyString::CMyString(CMyString const& other)
{

}

CMyString::CMyString(CMyString && other)
{

}

CMyString::CMyString(std::string const& stlString)
{

}

CMyString::~CMyString()
{
}

size_t CMyString::GetLength() const
{

}

const char* CMyString::GetStringData() const
{

}

CMyString const CMyString::SubString(size_t start, size_t length /*= SIZE_MAX*/) const
{

}

void CMyString::Clear()
{

}

CMyString const& CMyString::operator+(CMyString const & other) const
{

}

CMyString & CMyString::operator+=(CMyString const & other)
{

}

bool CMyString::operator!=(CMyString const & other) const
{

}

bool CMyString::operator==(CMyString const & other) const
{

}

CMyString & CMyString::operator=(CMyString const & other)
{

}

#include "stdafx.h"
#include <assert.h>
#include "MyString.h"

char CMyString::m_emptyStr[] = { '\0' };

CMyString::CMyString()
{
	m_first = CreateString(0);
	m_length = 0;
}

CMyString::CMyString(std::string const& stlString)
{
	auto len = stlString.size();
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, stlString.c_str(), m_length);
}

CMyString::CMyString(const char * pString)
{
	if (pString == nullptr)
	{
		throw std::invalid_argument("Can't create string from nullptr");
	}
	auto len = strlen(pString);
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, pString, m_length);
}

CMyString::CMyString(const char * pString, size_t length)
{
	if (pString == nullptr)
	{
		throw std::invalid_argument("Can't create string from nullptr");
	}
	m_first = CreateString(length);
	m_length = length;
	memcpy(m_first, pString, m_length);
}

CMyString::CMyString(CMyString const& other)
{
	auto len = other.GetLength();
	m_first = CreateString(len);
	m_length = len;
	memcpy(m_first, other.GetStringData(), m_length);
}

CMyString::CMyString(CMyString && other)
	: m_first(other.m_first)
	, m_length(other.m_length)
{
	other.m_first = nullptr;
	other.m_length = 0;
}


CMyString::CMyString(size_t len)
{
	m_first = CreateString(len);
	m_length = len;
}


void CMyString::SafeDelete(char * pString)
{
	if (pString && pString != m_emptyStr)
	{
		delete[] pString;
	}
}

char * CMyString::CreateString(size_t length)
{
	char * tmp = new char[length + 1];
	tmp[length] = '\0';
	return tmp;
}

size_t CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	if (!m_first)
	{
		return m_emptyStr;
	}
	return m_first;
}

CMyString CMyString::SubString(size_t start, size_t length /*= SIZE_MAX*/) const
{
	if (start > m_length)
	{
		throw std::out_of_range("Start pos should be less than string length");
	}
	if (start == m_length)
	{
		return CMyString();
	}
	else if ((m_length < start + length) || (start + length + 1) == start)
	{
		length = m_length - start;
	}
	return CMyString(m_first + start, length);
}

void CMyString::Clear()
{
	SafeDelete(m_first);
	m_first = nullptr;
	m_length = 0;
}

CMyString::iterator CMyString::begin()
{
	if (!m_first)
	{
		return iterator(m_emptyStr);
	}
	return m_first;
	
}

CMyString::constIterator CMyString::begin() const
{
	return constIterator(GetStringData());
}

CMyString::constIterator CMyString::end() const
{
	return constIterator(GetStringData() + m_length);
}

CMyString::iterator CMyString::end()
{
	if (!m_first)
	{
		return iterator(m_emptyStr);
	}
	return m_first + m_length;
}

CMyString::iterator CMyString::rbegin()
{
	if (!m_first)
	{
		return iterator(m_emptyStr, true);
	}
	return iterator(m_first + m_length, true);
}

CMyString::iterator CMyString::rend()
{
	if (!m_first)
	{
		return iterator(m_emptyStr, true);
	}
	return iterator(m_first, true);
}

CMyString::constIterator CMyString::rbegin() const
{
	return constIterator(GetStringData() + m_length, true);
}

CMyString::constIterator CMyString::rend() const
{
	return constIterator(GetStringData(), true);
}

CMyString & CMyString::operator+=(CMyString const & other)
{
	if (other.GetLength() != 0)
	{
		auto newData = CreateString(m_length + other.GetLength());
		memcpy(newData, GetStringData(), m_length);
		memcpy(newData + m_length, other.GetStringData(), other.GetLength());
		SafeDelete(m_first);
		m_first = newData;
		m_length += other.GetLength();
	}
	return *this;
}

bool CMyString::operator!=(CMyString const & other) const
{
	return !(*this == other);
}

bool CMyString::operator==(CMyString const & other) const
{
	if (other.GetLength() != m_length)
	{
		return false;
	}
	return memcmp(GetStringData(), other.GetStringData(), m_length) == 0;
}

CMyString & CMyString::operator=(CMyString && other)
{
	if (this != &other)
	{
		std::swap(m_first, other.m_first);
		std::swap(m_length, other.m_length);
		SafeDelete(other.m_first);
		other.m_first = m_emptyStr;
		other.m_length = 0;
	}
	return *this;
}

CMyString & CMyString::operator=(CMyString const & other)
{
	if (this != &other)
	{
		auto tmp = other;
		std::swap(m_first, tmp.m_first);
		std::swap(m_length, tmp.m_length);
	}
	return *this;
}


int CMyString::Compare(CMyString const& lhs, CMyString const& rhs)
{
	auto minLen = lhs.GetLength() < rhs.GetLength() ? lhs.GetLength() : rhs.GetLength();
	auto res = memcmp(lhs.GetStringData(), rhs.GetStringData(), minLen);
	if (res != 0)
	{
		return res;
	}
	return lhs.GetLength() > rhs.GetLength();
}

bool CMyString::operator<(CMyString const & other) const
{
	return Compare(*this, other) == -1;
}

bool CMyString::operator>(CMyString const & other) const
{
	return Compare(*this, other) == 1;
}

bool CMyString::operator>=(CMyString const & other) const
{
	return Compare(*this, other) != -1;
}

bool CMyString::operator<=(CMyString const & other) const
{
	return Compare(*this, other) != 1;
}

char & CMyString::operator[](size_t pos)
{
	assert(pos <= m_length);
	return m_first[pos];
}

char const& CMyString::operator[](size_t pos) const
{
	assert(pos <= m_length);
	return m_first[pos];
}

CMyString::~CMyString()
{
	SafeDelete(m_first);
}


std::istream & operator >> (std::istream & strm, CMyString & str)
{
	std::string tmp;
	strm >> tmp;
	str = tmp;
	return strm;
}

std::ostream & operator<<(std::ostream & strm, CMyString const& str)
{
	strm << str.GetStringData();
	return strm;
}


CMyString operator+(CMyString const & lhs, CMyString const & rhs)
{
	auto lhsLen = lhs.GetLength();
	auto rhsLen = rhs.GetLength();
	CMyString tmp(lhsLen + rhsLen);
	memcpy(tmp.m_first, lhs.GetStringData(), lhsLen);
	memcpy(tmp.m_first + lhsLen, rhs.GetStringData(), rhsLen);
	return tmp;
}

CMyString operator+(std::string const & lhs, CMyString const & rhs)
{
	auto lhsLen = lhs.size();
	auto rhsLen = rhs.GetLength();
	CMyString tmp(lhsLen + rhsLen);
	memcpy(tmp.m_first, lhs.c_str(), lhsLen);
	memcpy(tmp.m_first + lhsLen, rhs.GetStringData(), rhsLen);
	return tmp;
}

CMyString operator+(const char * lhs, CMyString const & rhs)
{
	auto lhsLen = strlen(lhs);
	auto rhsLen = rhs.GetLength();
	CMyString tmp(lhsLen + rhsLen);
	memcpy(tmp.m_first, lhs, lhsLen);
	memcpy(tmp.m_first + lhsLen, rhs.GetStringData(), rhsLen);
	return tmp;
}

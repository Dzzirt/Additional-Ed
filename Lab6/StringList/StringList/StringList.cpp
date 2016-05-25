//
// Created by nikita on 15.05.16.
//
#include "stdafx.h"
#include "StringList.h"
#include "StringListIterator.h"
#include <cassert>
#include <bitset>

using namespace std;

CStringList::CStringList(std::initializer_list<std::string> const& another)
{
    for (auto const& str : another)
    {
        Append(str);
    }
}

CStringList::CStringList(CStringList const &another)
{
    *this = another;
}

size_t CStringList::GetSize() const
{
    return m_size;
}

void CStringList::Append(const std::string & data)
{
    auto newNode = make_unique<Node>(data, m_lastNode, nullptr);
    Node *newLastNode = newNode.get();
    if (m_lastNode)
    {
        m_lastNode->next = move(newNode);
    }
    else // empty list
    {
        m_firstNode = move(newNode);
    }
    m_lastNode = newLastNode;
    ++m_size;
}

std::string & CStringList::GetBackElement()
{
    assert(m_lastNode);
    return m_lastNode->data;
}

std::string const & CStringList::GetBackElement() const
{
    assert(m_lastNode);
    return m_lastNode->data;
}
void CStringList::PushFront(const std::string &data)
{
    auto newNode = std::make_unique<Node>(data, nullptr, move(m_firstNode));
    if (newNode->next)
    {
        newNode->next->prev = newNode.get();
    }
    else
    {
        m_lastNode = newNode.get();
    }
    m_firstNode = move(newNode);
    m_size++;
}
std::string &CStringList::GetFrontElement()
{
    assert(m_firstNode);
    return m_firstNode->data;
}
std::string const &CStringList::GetFrontElement() const
{
    assert(m_firstNode);
    return m_firstNode->data;
}

void CStringList::operator=(std::initializer_list<std::string> const& another)
{
    Initialize(another);
}

void CStringList::operator=(CStringList const &another)
{
    Initialize(another);
}

bool CStringList::operator==(CStringList const &another) const
{
    if (m_size != another.m_size)
    {
        return false;
    }
    return std::equal(another.begin(), another.end(), begin());
}


bool CStringList::operator!=(CStringList const &another) const
{
    return !(*this == another);
}

const CStringListIterator CStringList::begin() const noexcept
{
    return CStringListIterator(m_firstNode.get(), this);
}

const CStringListIterator CStringList::end() const noexcept
{
    return CStringListIterator(nullptr, this);
}

const CStringListIterator CStringList::rbegin() const noexcept
{
    return CStringListIterator(m_lastNode, this, true);
}

const CStringListIterator CStringList::rend() const noexcept
{
    return CStringListIterator(nullptr, this, true);
}

CStringListIterator CStringList::begin() noexcept
{
    return CStringListIterator(m_firstNode.get(), this);
}

CStringListIterator CStringList::end() noexcept
{
    return CStringListIterator(nullptr, this);
}

CStringListIterator CStringList::rend() noexcept
{
    return CStringListIterator(nullptr, this, true);
}

CStringListIterator CStringList::rbegin() noexcept
{
    return CStringListIterator(m_lastNode, this, true);
}

bool CStringList::IsEmpty() const
{
    return m_size == 0;
}

void CStringList::Clear()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
    m_firstNode = nullptr;
    m_size = 0;
}

CStringListIterator CStringList::Insert(CStringListIterator const& pos, std::string const& data)
{
    if (pos == end())
    {
        Append(data);
        return CStringListIterator(--end());
    }
    else if (pos == begin())
    {
        PushFront(data);
        return CStringListIterator(begin());
    }
    else
    {
        auto newNode = make_unique<Node>(data, pos->prev, move(pos->prev->next));
        m_size++;
        pos->prev = newNode.get();
        newNode->prev->next = move(newNode);
        return CStringListIterator(pos->prev, this);
    }

}

CStringListIterator CStringList::Erase(CStringListIterator const& pos)
{
    m_size--;
    if ((!pos->prev) && (!pos->next))
    {
        m_firstNode = nullptr;
        m_lastNode = nullptr;
        return CStringListIterator(end());
    }
    else if (!pos->prev)
    {
        pos->next->prev = nullptr;
        m_firstNode = move(pos->next);
        return CStringListIterator(begin());
    }
    else if (!pos->next)
    {
        pos->prev->next = nullptr;
        m_lastNode = pos->prev;
        return CStringListIterator(end());
    }
    else
    {
        pos->next->prev = pos->prev;
        pos->prev->next = move(pos->next);
        return CStringListIterator(pos->prev->next.get(), this);
    }
}

CStringList::~CStringList()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
}

template<typename T>
void CStringList::Initialize(const T &iterableList)
{
    CStringList tmp;
    for (auto const& elem : iterableList)
    {
        tmp.Append(elem);
    }
    swap(m_firstNode, tmp.m_firstNode);
    swap(m_lastNode, tmp.m_lastNode);
    swap(m_size, tmp.m_size);
}


































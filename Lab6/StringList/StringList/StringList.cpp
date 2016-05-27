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

const_string_iterator CStringList::begin() const noexcept
{
    return const_string_iterator(m_firstNode.get(), this);
}

const_string_iterator CStringList::end() const noexcept
{
    return const_string_iterator(nullptr, this);
}

const_string_iterator CStringList::rbegin() const noexcept
{
    return const_string_iterator(m_lastNode, this, true);
}

const_string_iterator CStringList::rend() const noexcept
{
    return const_string_iterator(nullptr, this, true);
}

string_iterator CStringList::begin() noexcept
{
    return string_iterator(m_firstNode.get(), this);
}

string_iterator CStringList::end() noexcept
{
    return string_iterator(nullptr, this);
}

string_iterator CStringList::rend() noexcept
{
    return string_iterator(nullptr, this, true);
}

string_iterator CStringList::rbegin() noexcept
{
    return string_iterator(m_lastNode, this, true);
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

string_iterator CStringList::Insert(string_iterator const& pos, std::string const& data)
{
    if (pos == end())
    {
        Append(data);
        return string_iterator(--end());
    }
    else if (pos == begin())
    {
        PushFront(data);
        return string_iterator(begin());
    }
    else
    {
        auto newNode = make_unique<Node>(data, pos.m_node->prev, move(pos.m_node->prev->next));
        m_size++;
        pos.m_node->prev = newNode.get();
        newNode->prev->next = move(newNode);
        return string_iterator(pos.m_node->prev, this);
    }

}

string_iterator CStringList::Erase(string_iterator const& pos)
{
    m_size--;
    if ((!pos.m_node->prev) && (!pos.m_node->next))
    {
        m_firstNode = nullptr;
        m_lastNode = nullptr;
        return string_iterator(end());
    }
    else if (!pos.m_node->prev)
    {
        pos.m_node->next->prev = nullptr;
        m_firstNode = move(pos.m_node->next);
        return string_iterator(begin());
    }
    else if (!pos.m_node->next)
    {
        pos.m_node->prev->next = nullptr;
        m_lastNode = pos.m_node->prev;
        return string_iterator(end());
    }
    else
    {
        pos.m_node->next->prev = pos.m_node->prev;
        pos.m_node->prev->next = move(pos.m_node->next);
        return string_iterator(pos.m_node->prev->next.get(), this);
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


































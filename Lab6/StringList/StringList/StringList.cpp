//
// Created by nikita on 15.05.16.
//
#include "stdafx.h"
#include "StringList.h"
#include "StringListIterator.h"
#include <cassert>

using namespace std;

CStringList::CStringList()
    :m_size(0)
{

}

CStringList::CStringList(std::initializer_list<std::string> const& l)
    : m_size(0)
{
    for (auto const& str : l)
    {
        Append(str);
    }
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

void CStringList::operator=(std::initializer_list<std::string> const& l)
{
    Clear();
    for (auto const& str : l)
    {
        Append(str);
    }
}

CStringListIterator CStringList::begin() noexcept
{
    return CStringListIterator(m_firstNode.get());
}


CStringListIterator CStringList::end() noexcept
{
    return CStringListIterator();
}

CStringListIterator CStringList::rbegin() noexcept
{
    return CStringListIterator(m_lastNode, true);
}

CStringListIterator CStringList::rend() noexcept
{
    if (!m_firstNode)
    {
        return CStringListIterator(nullptr, true);
    }
    return CStringListIterator(m_firstNode->prev, true);
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

CStringListIterator CStringList::Insert(CStringListIterator const &posBefore, std::string const& data)
{
    auto node = make_unique<Node>(data, posBefore->prev, move(posBefore->prev->next));
    return CStringListIterator();
}

CStringListIterator CStringList::Erase(CStringListIterator const& pos)
{
    CStringListIterator tmp;
    if (!pos->prev && !pos->next)
    {
        m_firstNode = nullptr;
        m_lastNode = nullptr;
    }
    else if (!pos->prev)
    {
        pos->next->prev = nullptr;
        m_firstNode = move(pos->next);
        tmp = CStringListIterator(begin());
    }
    else if (!pos->next)
    {
        pos->prev->next = nullptr;
        m_lastNode = pos->prev;
        tmp = CStringListIterator(end());
    }
    else
    {
        pos->next->prev = pos->prev;
        pos->prev->next = move(pos->next);
        tmp = CStringListIterator(pos->prev->next.get());
    }
    m_size--;


    return tmp;
}

CStringList::~CStringList()
{
    //cout << "kek";
}

















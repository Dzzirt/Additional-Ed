//
// Created by nikita on 19.05.16.
//
#include "stdafx.h"
#include "StringListIterator.h"

CStringListIterator::CStringListIterator(CStringList::Node *node, const CStringList * list, bool isReverse)
    :m_node(node), m_isReverse(isReverse), m_list(list)
{
    if (!m_list)
    {
        throw std::invalid_argument("Pointer to list is nullptr");
    }
}

std::string & CStringListIterator::operator*() const
{

    return m_node->data;
}

CStringListIterator::pointer CStringListIterator::operator->() const
{
    return m_node;
}

CStringListIterator CStringListIterator::operator++(int)
{
    CStringListIterator tmp = *this;
    m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();
    return tmp;
}

CStringListIterator &CStringListIterator::operator++()
{
    m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();
    return *this;
}

CStringListIterator &CStringListIterator::operator--()
{
    if (!m_node)
    {
        m_node =  m_isReverse ? m_list->m_firstNode.get() : m_list->m_lastNode;
    }
    else
    {
        m_node =  m_isReverse ? m_node->next.get() : m_node->prev;
    }
    return *this;
}

CStringListIterator CStringListIterator::operator--(int)
{
    auto tmp = *this;
    if (!m_node)
    {
        m_isReverse ? m_node = m_list->m_firstNode.get() : m_node = m_list->m_lastNode;
    }
    else
    {
        m_isReverse ? m_node = m_node->next.get() : m_node = m_node->prev;
    }
    return tmp;
}

bool CStringListIterator::operator==(const CStringListIterator &other) const
{
    return m_node == other.m_node;
}

bool CStringListIterator::operator!=(const CStringListIterator &other) const
{
    return m_node != other.m_node;
}




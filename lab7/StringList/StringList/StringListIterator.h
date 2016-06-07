//
// Created by nikita on 19.05.16.
//
#pragma once
//#include "StringList.h"

template <typename D>
class CStringList;

template <typename T>
class CStringListIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
    friend class CStringList<T>;
    CStringListIterator(typename CStringList<T>::Node *node, const CStringList<T> * list, bool isReverse = false);
public:
    typename CStringListIterator<T>::reference operator*()const;
    typename CStringListIterator<T>::pointer operator->()const;
    CStringListIterator & operator++();
    CStringListIterator operator++(int);
    CStringListIterator & operator--();
    CStringListIterator operator--(int);
    bool operator==(CStringListIterator const &other) const;
    bool operator!=(CStringListIterator const &other) const;
private:
    typename CStringList<T>::Node * m_node = nullptr;
    const CStringList<T> * m_list;
    bool m_isReverse;
};
template <typename T>
CStringListIterator<T>::CStringListIterator(typename CStringList<T>::Node * node, const CStringList<T> * list, bool isReverse)
    :m_node(node), m_isReverse(isReverse), m_list(list)
{
    if (!m_list)
    {
        throw std::invalid_argument("Pointer to list is nullptr");
    }
}
template <typename T>
typename CStringListIterator<T>::reference CStringListIterator<T>::operator*() const
{

    return m_node->data;
}
template <typename T>
typename CStringListIterator<T>::pointer CStringListIterator<T>::operator->() const
{
    return &m_node->data;
}
template <typename T>
CStringListIterator<T> CStringListIterator<T>::operator++(int)
{
    CStringListIterator tmp = *this;
    m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();
    return tmp;
}
template <typename T>
CStringListIterator<T> &CStringListIterator<T>::operator++()
{
    m_isReverse ? m_node = m_node->prev : m_node = m_node->next.get();
    return *this;
}
template <typename T>
CStringListIterator<T> &CStringListIterator<T>::operator--()
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
template <typename T>
CStringListIterator<T> CStringListIterator<T>::operator--(int)
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
template <typename T>
bool CStringListIterator<T>::operator==(const CStringListIterator<T> &other) const
{
    return m_node == other.m_node;
}
template <typename T>
bool CStringListIterator<T>::operator!=(const CStringListIterator<T> &other) const
{
    return m_node != other.m_node;
}
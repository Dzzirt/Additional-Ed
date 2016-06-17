//
// Created by nikita on 15.05.16.
//
#pragma once
#include <memory>
#include <iostream>
#include <cassert>
#include "StringListIterator.h"

template <typename D>
struct Node
{
    Node(const D &data, Node *prev, std::unique_ptr<Node> &&next)
        : data(data), prev(prev), next(std::move(next))
    {
    }
    D data;
    Node *prev;
    std::unique_ptr<Node> next;
};

template <typename T>
class CStringList
{

    using MyNode = Node<T>;

public:

    typedef CStringListIterator<T, T> list_iterator;

    typedef CStringListIterator<const T, T> const_list_iterator;

    friend class CStringListIterator<T, T>;
    friend class CStringListIterator<const T, T>;

    CStringList() = default;
    CStringList(std::initializer_list<T> const &another);
    CStringList(CStringList const &another);
    void operator=(std::initializer_list<T> const &another);
    void operator=(CStringList const &another);
    bool operator==(CStringList const &another) const;
    bool operator!=(CStringList const &another) const;
    size_t GetSize() const;
    bool IsEmpty() const;
    void Append(const T &data);
    void PushFront(const T &data);
    void Clear();

    T &GetBackElement();
    T const &GetBackElement() const;
    T &GetFrontElement();
    T const &GetFrontElement() const;

    list_iterator Insert(list_iterator const &pos, T const &data);
    list_iterator Erase(list_iterator const &pos);

    list_iterator begin() noexcept;
    list_iterator end() noexcept;
    list_iterator rbegin() noexcept;
    list_iterator rend() noexcept;

    const_list_iterator begin() const noexcept;
    const_list_iterator end() const noexcept;
    const_list_iterator rbegin() const noexcept;
    const_list_iterator rend() const noexcept;

    ~CStringList<T>();
private:
    template <typename ListType>
    void Initialize(ListType const & iterableList);
    size_t  m_size = 0;
    std::unique_ptr<MyNode> m_firstNode = nullptr;
    MyNode *m_lastNode = nullptr;
};

template <typename T>
CStringList<T>::CStringList(std::initializer_list<T> const& another)
{
    for (auto const& str : another)
    {
        Append(str);
    }
}
template <typename T>
CStringList<T>::CStringList(CStringList<T> const &another)
{
    *this = another;
}
template <typename T>
size_t CStringList<T>::GetSize() const
{
    return m_size;
}
template <typename T>
void CStringList<T>::Append(const T & data)
{
    auto newNode = std::make_unique<MyNode>(data, m_lastNode, nullptr);
    MyNode *newLastNode = newNode.get();
    if (m_lastNode)
    {
        m_lastNode->next = std::move(newNode);
    }
    else // empty list
    {
        m_firstNode = std::move(newNode);
    }
    m_lastNode = newLastNode;
    ++m_size;
}
template <typename T>
T & CStringList<T>::GetBackElement()
{
    assert(m_lastNode);
    return m_lastNode->data;
}
template <typename T>
T const & CStringList<T>::GetBackElement() const
{
    assert(m_lastNode);
    return m_lastNode->data;
}
template <typename T>
void CStringList<T>::PushFront(const T &data)
{
    auto newNode = std::make_unique<MyNode>(data, nullptr, std::move(m_firstNode));
    if (newNode->next)
    {
        newNode->next->prev = newNode.get();
    }
    else
    {
        m_lastNode = newNode.get();
    }
    m_firstNode = std::move(newNode);
    m_size++;
}
template <typename T>
T &CStringList<T>::GetFrontElement()
{
    assert(m_firstNode);
    return m_firstNode->data;
}
template <typename T>
T const &CStringList<T>::GetFrontElement() const
{
    assert(m_firstNode);
    return m_firstNode->data;
}
template <typename T>
void CStringList<T>::operator=(std::initializer_list<T> const& another)
{
    Initialize(another);
}
template <typename T>
void CStringList<T>::operator=(CStringList<T> const &another)
{
    Initialize(another);
}
template <typename T>
bool CStringList<T>::operator==(CStringList<T> const &another) const
{
    if (m_size != another.m_size)
    {
        return false;
    }
    return std::equal(another.begin(), another.end(), begin());
}

template <typename T>
bool CStringList<T>::operator!=(CStringList<T> const &another) const
{
    return !(*this == another);
}
template <typename T>
typename CStringList<T>::const_list_iterator CStringList<T>::begin() const noexcept
{
    return CStringList<T>::const_list_iterator(m_firstNode.get(), this);
}

template <typename T>
typename CStringList<T>::const_list_iterator CStringList<T>::end() const noexcept
{
    return typename CStringList<T>::const_list_iterator(nullptr, this);
}
template <typename T>
typename CStringList<T>::const_list_iterator CStringList<T>::rbegin() const noexcept
{
    return typename CStringList<T>::const_list_iterator(m_lastNode, this, true);
}
template <typename T>
typename CStringList<T>::const_list_iterator CStringList<T>::rend() const noexcept
{
    return typename CStringList<T>::const_list_iterator(nullptr, this, true);
}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::begin() noexcept
{
    return typename CStringList<T>::list_iterator(m_firstNode.get(), this);
}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::end() noexcept
{
    return typename CStringList<T>::list_iterator(nullptr, this);
}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::rend() noexcept
{
    return typename CStringList<T>::list_iterator(nullptr, this, true);
}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::rbegin() noexcept
{
    return typename CStringList<T>::list_iterator(m_lastNode, this, true);
}
template <typename T>
bool CStringList<T>::IsEmpty() const
{
    return m_size == 0;
}
template <typename T>
void CStringList<T>::Clear()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
    m_firstNode = nullptr;
    m_size = 0;
}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::Insert(typename CStringList<T>::list_iterator const& pos, T const& data)
{
    if (pos == end())
    {
        Append(data);
        return typename CStringList<T>::list_iterator(--end());
    }
    else if (pos == begin())
    {
        PushFront(data);
        return typename CStringList<T>::list_iterator(begin());
    }
    else
    {
        auto newNode = std::make_unique<MyNode>(data, pos.m_node->prev, move(pos.m_node->prev->next));
        m_size++;
        pos.m_node->prev = newNode.get();
        newNode->prev->next = std::move(newNode);
        return typename CStringList<T>::list_iterator(pos.m_node->prev, this);
    }

}
template <typename T>
typename CStringList<T>::list_iterator CStringList<T>::Erase(typename CStringList<T>::list_iterator const& pos)
{
    m_size--;
    if ((!pos.m_node->prev) && (!pos.m_node->next))
    {
        m_firstNode = nullptr;
        m_lastNode = nullptr;
        return list_iterator(end());
    }
    else if (!pos.m_node->prev)
    {
        pos.m_node->next->prev = nullptr;
        m_firstNode = std::move(pos.m_node->next);
        return list_iterator(begin());
    }
    else if (!pos.m_node->next)
    {
        pos.m_node->prev->next = nullptr;
        m_lastNode = pos.m_node->prev;
        return list_iterator(end());
    }
    else
    {
        pos.m_node->next->prev = pos.m_node->prev;
        pos.m_node->prev->next = std::move(pos.m_node->next);
        return list_iterator(pos.m_node->prev->next.get(), this);
    }
}
template <typename T>
CStringList<T>::~CStringList<T>()
{
    while (m_lastNode)
    {
        m_lastNode->next = nullptr;
        m_lastNode = m_lastNode->prev;
    }
}
template <typename T>
template<typename ListType>
void CStringList<T>::Initialize(const ListType &iterableList)
{
    CStringList<T> tmp;
    for (auto & elem : iterableList)
    {
        tmp.Append(elem);
    }
    std::swap(m_firstNode, tmp.m_firstNode);
    std::swap(m_lastNode, tmp.m_lastNode);
    std::swap(m_size, tmp.m_size);
}


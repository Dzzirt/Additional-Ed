//
// Created by nikita on 19.05.16.
//
#pragma once
#include "StringList.h"




class CStringListIterator : public std::iterator<std::bidirectional_iterator_tag, CStringList::Node>
{
    friend class CStringList;
    CStringListIterator(CStringList::Node *node, const CStringList * list, bool isReverse = false);
public:
    std::string & operator*()const;
    CStringList::Node * operator->()const;
    CStringListIterator & operator++();
    CStringListIterator operator++(int);
    CStringListIterator & operator--();
    CStringListIterator operator--(int);
    bool operator==(CStringListIterator const &other) const;
    bool operator!=(CStringListIterator const &other) const;
private:
    CStringList::Node * m_node = nullptr;
    const CStringList * m_list;
    bool m_isReverse;
};

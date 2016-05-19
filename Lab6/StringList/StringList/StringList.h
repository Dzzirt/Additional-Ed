//
// Created by nikita on 15.05.16.
//
#pragma once
#include <memory>
#include <iostream>

class CStringListIterator;

class CStringList
{
    friend class CStringListIterator;
    struct Node
    {
        Node(const std::string & data, Node * prev, std::unique_ptr<Node> && next)
            : data(data), prev(prev), next(std::move(next))
        {
        }
        std::string data;
        Node *prev;
        std::unique_ptr<Node> next;

        ~Node()
        {
           // std::cout << "kek" << std::endl;
        }
    };

public:
    CStringList();
    CStringList(std::initializer_list<std::string> const& l);
    void operator=(std::initializer_list<std::string> const& l);
    ~CStringList();
    size_t GetSize()const;
    bool IsEmpty() const;
    void Append(const std::string& data);
    void PushFront(const std::string& data);
    void Clear();
    std::string & GetBackElement();
    std::string const& GetBackElement()const;
    std::string & GetFrontElement();
    std::string const& GetFrontElement()const;

    CStringListIterator Insert(CStringListIterator const& posBefore, std::string const& data);
    CStringListIterator Erase(CStringListIterator const& pos);
    CStringListIterator begin() noexcept;
    CStringListIterator end() noexcept;
    CStringListIterator rbegin() noexcept;
    CStringListIterator rend() noexcept;
private:
    size_t m_size = 0;
    std::unique_ptr<Node> m_firstNode;
    Node * m_lastNode;
};


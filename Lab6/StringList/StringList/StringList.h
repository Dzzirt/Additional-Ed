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
        Node(const std::string &data, Node *prev, std::unique_ptr<Node> &&next)
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
    CStringList() = default;
    CStringList(std::initializer_list<std::string> const &another);
    CStringList(CStringList const &another);
    void operator=(std::initializer_list<std::string> const &another);
    void operator=(CStringList const &another);
    bool operator==(CStringList const &another) const;
    bool operator!=(CStringList const &another) const;
    size_t GetSize() const;
    bool IsEmpty() const;
    void Append(const std::string &data);
    void PushFront(const std::string &data);
    void Clear();

    std::string &GetBackElement();
    std::string const &GetBackElement() const;
    std::string &GetFrontElement();
    std::string const &GetFrontElement() const;

    CStringListIterator Insert(CStringListIterator const &pos, std::string const &data);
    CStringListIterator Erase(CStringListIterator const &pos);

    CStringListIterator begin() noexcept;
    CStringListIterator end() noexcept;
    CStringListIterator rbegin() noexcept;
    CStringListIterator rend() noexcept;

    const CStringListIterator begin() const noexcept;
    const CStringListIterator end() const noexcept;
    const CStringListIterator rbegin() const noexcept;
    const CStringListIterator rend() const noexcept;

    ~CStringList();
private:
    template <typename T>
    void Initialize(T const & iterableList);
    size_t  m_size = 0;
    std::unique_ptr<Node> m_firstNode = nullptr;
    Node *m_lastNode = nullptr;
};


//
// Created by nikita on 15.05.16.
//
#pragma once
#include <memory>
#include <iostream>

template <typename T>
class CStringListIterator;


typedef CStringListIterator<std::string> string_iterator;
typedef CStringListIterator<const std::string> const_string_iterator;

class CStringList
{

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
    template <typename T>
    friend class CStringListIterator;

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

    string_iterator Insert(string_iterator const &pos, std::string const &data);
    string_iterator Erase(string_iterator const &pos);

    string_iterator begin() noexcept;
    string_iterator end() noexcept;
    string_iterator rbegin() noexcept;
    string_iterator rend() noexcept;

    const_string_iterator begin() const noexcept;
    const_string_iterator end() const noexcept;
    const_string_iterator rbegin() const noexcept;
    const_string_iterator rend() const noexcept;

    ~CStringList();
private:
    template <typename T>
    void Initialize(T const & iterableList);
    size_t  m_size = 0;
    std::unique_ptr<Node> m_firstNode = nullptr;
    Node *m_lastNode = nullptr;
};


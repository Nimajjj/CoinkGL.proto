//
// Created by Benjamin on 11/12/2022.
//

#pragma once

#include <type_traits>
#include <memory>

template <typename T>
struct Node {
 typedef std::shared_ptr<Node<T>>  NodePtr;

 public:
  Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
  ~Node() = default;

  T data;
  NodePtr next;
  NodePtr prev;
};


template <class T>
class LinkedList {
  typedef std::shared_ptr<Node<T>>  NodePtr;

  public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {};
    ~LinkedList() = default;

    void PushBack(const T& data);
    void PushFront(const T& data);
    void Remove(const unsigned int& index);
    void Remove(const T& data);
    void Clear();

    T& At(const unsigned int& index);

    bool Contains(const T& data) const;
    const unsigned int& Size() const;

    T& operator[](const unsigned int& index);

    // getters
    NodePtr Head() const { return head; }
    NodePtr Tail() const { return tail; }


  private:
    NodePtr head;
    NodePtr tail;
    unsigned int size;
};
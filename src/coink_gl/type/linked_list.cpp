//
// Created by Benjamin on 11/12/2022.
//

#include "type/linked_list.h"

template <typename T>
void LinkedList<T>::PushBack(const T& data) {
  NodePtr node = std::make_shared<Node<T>>(data);

  if (head == nullptr) {
    head = node;
    tail = node;
    size++;
    return;
  }

  // add to the end of the list if tail->data is the same type as data
  if (!std::is_same<T, typename std::remove_reference<decltype(tail->data)>::type>::value) {
    return;
  }

  tail->next = node;
  node->prev = tail;
  tail = node;
}

template <typename T>
void LinkedList<T>::PushFront(const T& data) {
  NodePtr node = std::make_shared<Node<T>>(data);

  if (head == nullptr) {
    head = node;
    tail = node;
    size++;
    return;
  }

  // add to the end of the list if tail->data is the same type as data
  if (!std::is_same<T, typename std::remove_reference<decltype(head->data)>::type>::value) {
    return;
  }

  head->prev = node;
  node->next = head;
  head = node;
}


template <typename T>
void LinkedList<T>::Remove(const unsigned int& index) {
  if (index >= size) {
    return;
  }

  NodePtr node = head;
  for (unsigned int i = 0; i < index; i++) {
    node = node->next;
  }

  if (node->prev != nullptr) {
    node->prev->next = node->next;
  }

  if (node->next != nullptr) {
    node->next->prev = node->prev;
  }

  if (node == head) {
    head = node->next;
  }

  if (node == tail) {
    tail = node->prev;
  }

  size--;
}

template <typename T>
void LinkedList<T>::Remove(const T& data) {
  NodePtr node = head;
  while (node != nullptr) {
    if (node->data == data) {
      if (node->prev != nullptr) {
        node->prev->next = node->next;
      }

      if (node->next != nullptr) {
        node->next->prev = node->prev;
      }

      if (node == head) {
        head = node->next;
      }

      if (node == tail) {
        tail = node->prev;
      }

      size--;
      return;
    }

    node = node->next;
  }
}


template <typename T>
void LinkedList<T>::Clear() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}


template <typename T>
T& LinkedList<T>::At(const unsigned int& index) {
  if (index >= size) {
    return head->data;
  }

  NodePtr node = head;
  for (unsigned int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
}



template <typename T>
bool
LinkedList<T>::Contains(const T& data) const {
  NodePtr node = head;
  while (node != nullptr) {
    if (node->data == data) {
      return true;
    }

    node = node->next;
  }

  return false;
}


template <typename T>
const unsigned int&
LinkedList<T>::Size() const {
  return size;
}


template <typename T>
T& LinkedList<T>::operator[](const unsigned int& index) {
  if (index >= size) {
    return head->data;
  }

  NodePtr node = head;
  for (unsigned int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
}
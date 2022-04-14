#include "assignment/linked_list.hpp"

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* node = front_;
    Node* prev = nullptr;
    while (node != back_) {
      auto next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    if (node == back_) {
      node->next = prev;
    }
    Node* n = back_;
    back_ = front_;
    front_ = n;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* n = back_;
    back_ = front_;
    front_ = n;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    Node* nextNode = curr->next;
    curr->next = prev;
    if (nextNode != nullptr) {
      reverse_recursive_helper(nextNode, curr);
    }
  }

}  // namespace assignment

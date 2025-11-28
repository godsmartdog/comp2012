#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include "Ticket.h"

using namespace std;

template <typename T>
class BST {
  private:
    struct BSTNode {
      T* data;
      BST<T> left;
      BST<T> right;
      explicit BSTNode(T* data) : data(data) {}
    };

    BSTNode* root = nullptr;

    using KeyType = typename T::KeyType;

  public:
    BST() = default;

    // * Task 3.1: initialization
    BST(const BST& bst);

    // * Task 3.2: destruction
    ~BST();

    BST(BST&&) = delete;
    BST& operator= (const BST&) = delete;
    BST& operator= (BST&&) = delete;

    // * Task 3.2: destruction
    void clear();

    // * Task 3.3: BST insertion
    void add(T* data);

    // * Task 3.4: iteration
    void print() const;

    // * Task 3.5: BST searching
    const BST<T>* find(const KeyType& key) const;
    // * Task 3.5: BST searching
    T* getData() const;

    // * Task 3.6: kth least
    int getSize() const;
    // * Task 3.6: kth least
    const BST<T>* getKth(int k) const;

    // * Task 3.7: remove
    void remove(T* data);
};


#include "BSTImplementation.h"

#endif // __BST_H__

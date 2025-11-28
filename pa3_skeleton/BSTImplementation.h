#ifndef __BST_IMPLEMENTATION_H__
#define __BST_IMPLEMENTATION_H__

#include "BST.h"

template<typename T>
BST<T>::BST(const BST& bst):root(nullptr){
        root=new BSTNode(*bst.root);
    }

template<typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
void BST<T>::clear() {
    if (root != nullptr) {
        root->left.clear();  
        root->right.clear();  
        delete root;          
        root = nullptr;
    }
}
template <typename T>
void BST<T>::add(T* data) {
    if (data == nullptr) {
        return;
    }
    
    if (root == nullptr) {
      
        root = new BSTNode(data);
        return;
    }
    
    BST<T>* current = this;
    while (true) {
        if (*data < *(current->root->data)) {
            
            if (current->root->left.root == nullptr) {
                current->root->left.root = new BSTNode(data);
                return;
            }
            current = &(current->root->left);
        } else if (*(current->root->data) < *data) {
            // Go right
            if (current->root->right.root == nullptr) {
                current->root->right.root = new BSTNode(data);
                return;
            }
            current = &(current->root->right);
        } else {
           
            return;
        }
    }
}
template<typename T>
void BST<T>:: print() const{
    if(root==nullptr){
        return;
    }
    root->left.print();
    cout<< root->data->toString()<<endl;
    root->right.print();
}
template <typename T>
T* BST<T>::getData() const {
    if (root == nullptr) {
        return nullptr;
    }
    return root->data;
}

template <typename T>
const BST<T>* BST<T>::find(const KeyType& key) const {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (*(root->data) == key) {
        return this;
    } else if (*(root->data) < key) {
        return root->right.find(key);
    } else {
        return root->left.find(key);
    }
}
template <typename T>
int BST<T>::getSize() const {
    if (root == nullptr) {
        return 0;
    }
    return 1 + root->left.getSize() + root->right.getSize();
}

template <typename T>
const BST<T>* BST<T>::getKth(int k) const {
    if (root == nullptr || k < 0 || k >= getSize()) {
        return nullptr;
    }
    
    int leftSize = root->left.getSize();
    
    if (k < leftSize) {
        return root->left.getKth(k);
    } else if (k == leftSize) {
        return this;
    } else {
        return root->right.getKth(k - leftSize - 1);
    }
}

template <typename T>
void BST<T>::remove(T* data) {
    if (data == nullptr || root == nullptr) {
        return;
    }
    
    if (*data < *(root->data)) {
        root->left.remove(data);
    } else if (*(root->data) < *data) {
        root->right.remove(data);
    } else {
        
        if (root->left.root == nullptr && root->right.root == nullptr) {
            
            delete root;
            root = nullptr;
        } else if (root->left.root == nullptr) {
           
            BSTNode* temp = root;
            root = root->right.root;
            temp->right.root = nullptr;
            delete temp;
        } else if (root->right.root == nullptr) {
          
            BSTNode* temp = root;
            root = root->left.root;
            temp->left.root = nullptr; 
            delete temp;
        } else {
           
            BST<T>* maxLeft = &(root->left);
            while (maxLeft->root->right.root != nullptr) {
                maxLeft = &(maxLeft->root->right);
            }
            
           
            T* tempData = root->data;
            root->data = maxLeft->root->data;
            maxLeft->root->data = tempData;
            
           
            root->left.remove(maxLeft->root->data);
        }
    }
}

#endif // __BST_IMPLEMENTATION_H__

#ifndef __BST_IMPLEMENTATION_H__
#define __BST_IMPLEMENTATION_H__

#include "BST.h"

BST::BST(const BST& bst):root(nullptr){
        if (bst.root != nullptr) {
        root = new BSTNode(bst.root->data);  // Shallow copy data
        
        // Manually copy left subtree
        if (bst.root->left.root != nullptr) {
            root->left = BST<T>(bst.root->left);  // Recursive copy
        }
        
        // Manually copy right subtree  
        if (bst.root->right.root != nullptr) {
            root->right = BST<T>(bst.root->right);  // Recursive copy
        }
    }
}

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
        // Tree is empty, create new root node
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
void BST:: print() const{
    if(root==nullptr){
        return;
    }
    root->left.print();
    cout<< root->data->toString()<<endl;
    root->right.print();
}


#endif // __BST_IMPLEMENTATION_H__

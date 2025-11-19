#include "BST.h"
#include <iostream>

using namespace std;

/**
 * Returns an integer < 0 if the first Song is shorter compared to the second,
 * 0 if they are equivalent, or > 0 if the first Song is longer than the second.
 */
int compare_by_length(const Song& one, const Song& two){
    
    return (one.length-two.length);
}

/**
 * Returns an integer < 0 if the name of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the name of the first Song is lexicographically after the name of the second.
 */
int compare_by_name(const Song& one, const Song& two){
  
   return(one.name.compare(two.name));
}


/**
 *
 * Returns an integer < 0 if the artist of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the artist of the first Song is lexicographically after the name of the second.
 */
int compare_by_artist(const Song& one, const Song& two){
    return one.artist.compare(two.artist);
}

BST::BST(int(**compare_funcs)(const Song& ,const Song&),int value):root(nullptr), compare_funcs(compare_funcs),func_length(value){

}
BST::~BST(){
if(root!=nullptr){
    delete root;
}
}

BST::BSTNode::BSTNode(const Song&song):song(song),left_count(0),right_count(0),left(nullptr),right(nullptr){}
    
BST::BSTNode::~BSTNode(){
    delete left;
    delete right;
}
void BST::insert(const Song& song1){
    
    if(root==nullptr){
        root=new BSTNode(song1);
    }
    
    for(int i=0;i<func_length;i++){
        int tmp=compare_funcs[i](song1,root->song);
        if(tmp==0){
            continue;
        }
        if(tmp>0){
            if(root->left==nullptr){
                root->left=new BST(compare_funcs,func_length);
            }
            root->left->insert(song1);
        }
        if(tmp<0){
            if (root->right == nullptr) {
                root->right = new BST(compare_funcs, func_length);
            }
           root->right->insert(song1);
        }
    }
    

}

bool BST::contains(const Song& song1) const{
    if(root==nullptr){
        return false;
    }
    int compare=-1;
       for(int i=0;i<func_length;i++){
        int tmp=compare_funcs[i](song1,root->song);
        if(tmp==0){
            continue;
        }
        if(tmp>0){
            compare=2;
            break;
        }
        if(tmp<0){
            compare=1;
            break;
        }
    }
    if(compare==-1){
        return true;
    }
    if(compare==1){
        if(root->right!=nullptr)
        return root->right->contains(song1);
        return false;
    }
    if(root->left!=nullptr)
    return root->left->contains(song1);
    return false;
}

void BST::print_in_order() const{
    if(root==nullptr)
    return;
    if(root->left!=nullptr)
    root->left->print_in_order();
    root->song.to_string();
    if(root->right!=nullptr)
    root->right->print_in_order();

}

void BST:: print_nth(int n) const{
    if (root == nullptr || n < 1 || n > (root->left_count + root->right_count + 1)) {
        cout << "Song unavailable.\n";
        return;
    }
  
    const BSTNode* tmp = root;
    while(tmp!=nullptr){
        if(n<=tmp->left_count){
            tmp=tmp->left->root;
            
        }
        else if(n==tmp->left_count+1){
            tmp->song.to_string();
            return;
        }
        else{
            n=n-tmp->left_count-1;
            tmp=tmp->right->root;
        }
    }
}
BST::BST(const BST& x): root(nullptr), compare_funcs(x.compare_funcs), func_length(x.func_length){
    if (x.root==nullptr)
        return;

    root = new BSTNode(*x.root);
}
BST::BSTNode::BSTNode(const BSTNode& x):song(x.song),left_count(x.left_count),right_count(x.right_count),left(x.left),right(x.right){

}
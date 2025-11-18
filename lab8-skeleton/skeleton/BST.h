#ifndef BST_H
#define BST_H

#include "Song.h"

/**
 * Returns an integer < 0 if the first Song is shorter compared to the second,
 * 0 if they are equivalent, or > 0 if the first Song is longer than the second.
 */
int compare_by_length(const Song&, const Song&);

/**
 * Returns an integer < 0 if the name of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the name of the first Song is lexicographically after the name of the second.
 */
int compare_by_name(const Song&, const Song&);

/**
 *
 * Returns an integer < 0 if the artist of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the artist of the first Song is lexicographically after the name of the second.
 */
int compare_by_artist(const Song&, const Song&);

class BST {
private:
    // A node in a BST
    struct BSTNode {
        Song song;
        int left_count, right_count;
        BST *left;
        BST *right;

        // Create a new BSTNode with a Song
        BSTNode(const Song&);
        // Copy Constructor (Deep Copy of BST, not Songs)
        BSTNode(const BSTNode&);
        ~BSTNode();
    };

    BSTNode *root;
    // An array of function pointers in the order with which you will compare songs
    int (**compare_funcs)(const Song&, const Song&);
    // Length of the compare_funcs array
    int func_length;

public:
    // Constructor with function pointer array
    BST(int (**)(const Song&, const Song&), int);
    // Copy Constructor (Deep Copy of BST, not Songs)
    BST(const BST&);
    ~BST();

    // Insert a song into the BST
    void insert(const Song&);

    // Find out if a BST contains a song already
    bool contains(const Song&) const;

    // Print the songs in a BST in ascending order; Use Song::to_string() for formatting
    void print_in_order() const;

    // Print the n-th data on the BST; Use Song::to_string() without indentation for formatting
    void print_nth(int) const;
};

#endif
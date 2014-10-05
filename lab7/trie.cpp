/*
 * trie.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: dheerendra
 */

#include "trie.h"

#include <cstdlib>
#include <iostream>
using namespace std;

/**
 * constructor of Node implementation
 */
Node::Node(char x) {
    val = x;
    flag = 0; /** default value of flag is 0 */
    index = -1; /** default value of index is -1 (useful when no ip is matched) */
    this->child[0] = NULL;
    this->child[1] = NULL;
}

/**
 * Implementing Node destructor
 */
Node::~Node(){
    delete[] *child;
}

/**
 * default trie constructor
 */
Trie::Trie() {
    this->root = new Node(0);
}

/**
 * insertion function for trie implementation
 * @param s string to be inserted into trie
 * @param index index of string inserted into the array in which that is stored
 */
void Trie::insert(string s, int index) {
    Node* curr = root;  /** starting from the root node */
    int len = s.length();
    if (len == 0) /** if empty string is given then nothing will be inserted */
        return;

    /* Iterating till the second last character,
     * last character is handled specially.
     * And only a binary string of network address is inserted
     * String length = network bits + sub-net bits
     */
    for (int i = 0; i < len - 1; i++) {
        int temp = s[i] - '0';
        if (!curr->child[temp]) {
            curr->child[temp] = new Node(s[i]);
        }
        curr = curr->child[temp];
    }
    /* terminating case is handled here */
    int temp = s[len - 1] - '0';
    if (!curr->child[temp])
        curr->child[temp] = new Node(s[len - 1]);
    /*
     * Since network address ends here, string till this node will represent the valid
     * network address and flag is set to 1 and index is set to string index.
     */
    curr->child[temp]->flag = 1;
    curr->child[temp]->index = index;

}

/*
 * Implementation of getting index of longest prefix matched.
 */
int Trie::getindex(string s) {
    Node* curr = root;
    int ans = -1;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        int temp = s[i] - '0';
        if (!curr->child[temp]) /* if no more matching child is present then break */
            break;
        else {
            curr = curr->child[temp];
            /* whenever encounters a valid network address
             * then update index
             */
            if (curr->flag) {
                ans = curr->index;
            }
        }
    }
    return ans;
}

/**
 * Implementing destructor
 */
Trie::~Trie(){
    delete root;
}


/*
 * trie.h
 *
 *  Created on: Oct 5, 2014
 *      Author: dheerendra
 */

#ifndef NETWORKS_TRIE_H_
#define NETWORKS_TRIE_H_

#include<string>

/**
 * Node declaration
 */
struct Node {
    char val; /** values to be stored in node (0 or 1) */
    Node* child[2]; /** pointers to two child node corresponding to 0 and 1 */
    bool flag; /** flag for ensuring whether this node completes a network address */
    int index; /** if flag is true then this will contain the corresponding
     index of ip-address and subnet number in a vector storing them*/

    Node(char x); /** constructor declaration */

    ~Node(); /** destructor declaration */
};

/**
 * Trie struct declaration
 */
struct Trie {
    Node* root;     /** root Node declaration */
    Trie();         /** default constructor declaration */
    void insert(std::string, int); /** insert string and it's index declaration */
    int getindex(std::string); /** declaration for getting index of prefix-matched string */
    ~Trie(); /** destructor declaration */
};

#endif /* NETWORKS_TRIE_H_ */

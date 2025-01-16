#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class Node{
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node();

    Node* createNode( int data );

    void insertNode( int data );

    void printTree( Node* root );

    void preOrder( Node* root );

    void postOrder( Node* root );

    void inOrder( Node* root );

    std::vector <std::vector <int >> levelOrder( Node* root );

    void printLevelOrder( std::vector< std::vector < int >> treeElements );

    int heightOfTree( Node* root );

    bool isBalanced( Node* root ); 

};

#endif // BINARY_TREE
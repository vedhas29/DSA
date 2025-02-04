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

    int treeDiameter( Node* root );
    int getDiameter();

    std::vector <int> leftViewOfTree( Node* root );

    std::vector <int> rightViewOfTree( Node* root );

    bool areBothTreesSame( Node* p, Node* q );

    std::vector < vector <int>> zigzagLevelOrder( Node* root );

    void FlattenBT2LL( Node* root );
    void preOrder2StoreElements( Node* root, std::vector <int>& elements );

    void createMirror( Node* root );

    Node* searchInBST( Node* root, int key );

    Node* constructBTFromPreoder( std::vector<int> preorder );

//Note:- In an inorder traversal the number just smaller than the target is
//the predecessor and the number just greater than the target is the successor. 
    void find_Predecessor_Successor( Node* root, int target );

    //LC-116 Populating Next right pointers in each nodes
    struct mNode {
        int data;
        mNode* left = nullptr;
        mNode* right = nullptr;
        mNode* next = nullptr;
    };
    mNode* connect( mNode* root );

    //LC-98 validate BST 
    bool isValidBST( Node* root );

    //GFG Root to Leaf Path
    void root2LeafPath( Node* root, std::vector<int>& pathElements, 
                    std::vector<std::vector<int>>& treeElements );

    //LC-230 Kth smallest element in BST
    int kthSmallest( Node* root, int k );

private:
    int diameter = 0; //required for tree diameter

};

#endif // BINARY_TREE
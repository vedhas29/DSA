#include "binary_tree.h"
#include <iostream>

using namespace std;

Node::Node() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node* Node::createNode( int data ) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    // cout << "node created" << endl;
    return newnode;
}

void Node::insertNode( int data ) {
    
    if ( data <= this->data ) {
        //if left is empty then create new node and add to left
        if ( this->left == nullptr ) {
            this->left = createNode( data );
        }
       else { //if left is not empty then traverse to left side
            this->left->insertNode( data );
        }
    }
    if ( data > this->data ) {
        if ( this->right == nullptr ) {
            this->right = createNode( data );
        }
        else {
            this->right->insertNode( data );
        }
    }

}

void Node::printTree( Node* root ){
    if( root == NULL ) {
        return;
    }
    
    root->printTree( root->left );
    cout << root->data << " ";
    root->printTree( root->right );

    return;
}

void Node::preOrder( Node* root ) {
    if ( root == NULL ) {
        return;
    }

    std::cout << root->data << " ";
    preOrder( root->left );
    preOrder( root->right ); 
}

void Node::inOrder( Node* root ) {
    if ( root == NULL ) {
        return;
    }

    inOrder( root->left );
    std::cout << root->data << " ";
    inOrder( root->right );
}

void Node::postOrder( Node* root ) {
    if ( root == NULL ) {
        return;
    }

    postOrder( root->left );
    postOrder( root->right );
    std::cout << root->data << " ";
}

std::vector<std::vector <int >> Node::
levelOrder( Node* root ) {
    std::vector< std::vector < int >> treeElements;

    if ( root == nullptr ) {
        std::cout << "Tree Empty";
    }

    std::queue <Node*> q;
    q.push( root );

    while( !q.empty()) {
        std::vector <int> currentLevel;
        int q_size = q.size();

        for ( int i = 0; i < q_size; i++ ) { //q_size instead of q.size() to 
                                            //avoid dynamic size changes during loop
            Node* node = q.front();
            q.pop();

            if ( node->left != nullptr ) {
                q.push( node->left );
            }

            if ( node->right != nullptr ) {
                q.push( node->right );
            }

            currentLevel.push_back( node->data );
        }
        treeElements.push_back( currentLevel );
    }

    return treeElements;
}

void Node::printLevelOrder( std::vector< std::vector < int >> treeElements ) {

    std::cout << "\nLevel Order traversal of Tree = " << std::endl;

    for ( int i = 0; i < treeElements.size(); i++ ) {
        for ( int j = 0; j < treeElements[ i ].size(); j++ ) {
            std::cout << treeElements[ i ][ j ];
        }
        std::cout << std::endl;
    }
    
}

int Node::heightOfTree( Node* root ) {
    if ( root == nullptr ) {
        return 0;
    }
    return max( heightOfTree( root->left), heightOfTree( root->right))+1;
}

bool Node::isBalanced( Node* root ) {

    if( root == nullptr ) {
        return 0;
    }

    int leftHeight = heightOfTree( root->left );
    int rightHeight = heightOfTree( root->right );

    if ( abs( leftHeight - rightHeight ) > 1 ) {
        return false;
    } else if ( abs( leftHeight - rightHeight ) <= 1 ) {
        return true;
    }

}
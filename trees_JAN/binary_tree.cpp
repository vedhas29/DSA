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

std::vector <std::vector <int >> Node::levelOrder( Node* root ) {
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

int Node::treeDiameter( Node* root ) {
    if ( root == nullptr ) {
        return 0;
    }

    int left = heightOfTree( root->left );
    int right = heightOfTree( root->right );
    int sum = left + right;
    diameter = max( diameter, sum );
    return max( left, right )+1;
}

int Node::getDiameter() {
    return diameter;
}

std::vector <int> Node::leftViewOfTree( Node* root ) {
    if ( root == nullptr ) {
        return {};
    }

    std::vector <std::vector <int>> treeElements = levelOrder( root );

    std::vector <int> leftViewElements;

    for ( int i = 0; i < treeElements[ i ].size(); i++ ) {
        for ( int j = 0; j < treeElements[ i ].size(); j++ ) {
            if ( j == 0 ) {
                leftViewElements.push_back( treeElements[ i ][ j ] );
            }
        }
    }

    return leftViewElements;
}

std::vector <int> Node::rightViewOfTree( Node* root ) {
    if ( root == nullptr ) {
        return {};
    }

    std::vector <std::vector <int>> treeElements = levelOrder( root );

    std::vector <int> rightViewElements;

    for ( int i = 0; i < treeElements.size(); i++ ) {
        for (int j = 0; j < treeElements[ i ].size(); j++) {
            if ( j == treeElements[ i ].size() - 1 ) {
                rightViewElements.push_back( treeElements[ i ][ j ] );
            }
        }
    }

    return rightViewElements;
}

bool Node::areBothTreesSame( Node* p, Node* q ) {
    
    // if both are nullptr
    if ( p == nullptr && q == nullptr ) {
        return true;
    }

    // if either is nullptr and other is not
    if ( p == nullptr || q == nullptr ) {
        return false;
    }

    // if p->data and q->data are same then check their subtrees recursively
    if ( p->data == q->data ) {
        return ( areBothTreesSame( p->left, q->left ) && 
                areBothTreesSame( p->right, q->right ));
    }

    // if p->data and q->data are not same then return false
    return false;
}

std::vector < std::vector <int>> Node::zigzagLevelOrder( Node* root ) {

    std::vector < std::vector <int>> zigzagElements = levelOrder( root );


    for ( int i = 0; i < zigzagElements.size(); i++ ) {
        if ( i % 2 != 0 ) {
            reverse( zigzagElements[ i ].begin(), zigzagElements[ i ].end());
        }
    }

    return zigzagElements;
}

void Node::FlattenBT2LL( Node* root ) {

    if ( root == nullptr ) {
        return;
    }

    std::vector <int> elements;
    preOrder2StoreElements( root, elements );

    root->left = nullptr;
    Node* temp = root;

    for ( int i = 1; i < elements.size(); i++ ) {
        Node* newNode = createNode( root->data );
        temp->right = newNode;
        temp = newNode; 
    }

}

void Node::preOrder2StoreElements( Node* root, std::vector <int>& elements ) {
    
    if ( root == nullptr ) {
        return;
    }

    elements.push_back( root->data );
    preOrder2StoreElements( root->left, elements );
    preOrder2StoreElements( root->right, elements );
}

void Node::createMirror( Node* root ) {

    if ( root == nullptr ) {
        return;
    }

    swap( root->left, root->right );
    createMirror( root->left );
    createMirror( root->right );
}

Node* Node::searchInBST( Node* root, int key ) {

    if ( root == nullptr ) {
        return nullptr;
    }

    std::queue <Node*> q;
    q.push( root );

    while ( !q.empty()) {
        Node* element = q.front();
        q.pop();

        if ( element->left != nullptr ) {
            q.push( element->left );
        }

        if ( element->right != nullptr ) {
            q.push( element->right );
        }

        if ( element->data == key ) {
            return element;
        }
    }

    return nullptr;
}

Node* createNode( int data ) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

void insertNode( Node* node, std::vector<int>& preorder, int i ) {
    
    ////node is not present the simply return
    if ( node == nullptr ) {
        return;
    }
    
    //if node is present and node val is  greater than cuurent val to be inserted
    //new node should go in left sub tree
    if ( preorder[ i ] <= node->data ) {

        //if node left is not present then create new Node
        if ( node->left != nullptr ) {
            node->left = createNode( preorder[ i ] );
        }

        //if node left is present then traverse to left again
        if ( node->left == nullptr ) {
            insertNode( node->left, preorder, i );
        }
    }

    //if node is present and node val is smaller than current val to be inserted
    //new node should go in right sub tree
    if ( preorder[ i ] > node->data ) {
        
        //if node right is not present then create new node
        if ( node->right != nullptr ) {
            node->right = createNode( preorder[ i ] );
        }

         //if node right is present then traverse to right again
        if ( node->right == nullptr ) {
            insertNode( node->right, preorder, i );
        }
    }

}

Node* Node::constructBTFromPreoder( std::vector<int> preorder ) {

    if ( preorder.size() == 0 ) {
        return nullptr;
    }

    Node* root = createNode( preorder[ 0 ] );

    for ( int i = 1; i < preorder.size(); i++ ) {
        insertNode( root, preorder,i );
    }

    return root;
}

void inorderTraversal( Node* root, std::vector <Node*>& inorderElements ) {

    if ( root == nullptr ) {
        return;
    }

    inorderTraversal( root->left, inorderElements );

    inorderElements.push_back( root );

    inorderTraversal( root->right, inorderElements );
}

void Node::find_Predecessor_Successor( Node* root, int target ) {

    std::vector <Node*> inorderElements;

    inorderTraversal( root, inorderElements );

    Node* predecessor = nullptr;
    Node* successor = nullptr;

    for ( int i = 0; i < inorderElements.size(); i++ ) {

        if ( inorderElements[ i ]->data < target ) {
            predecessor = inorderElements[ i ];
        }

        if ( inorderElements[ i ]-data > target ) {
            successor = inorderElements[ i ];
            break;
        }
    }
}

Node::mNode* Node::connect( mNode* root ) {

    if ( root == nullptr ) {
        return nullptr;
    }

    std::vector <std::vector <mNode*>> treeElements;

    std::queue <mNode*> q;
    q.push( root );

    while ( !q.empty()) {
        std::vector <mNode*> currLevelElements;
        int q_size = q.size();

        for ( int i = 0; i < q_size; i++ ) {
            mNode* node = q.front();
            q.pop();

            if ( node->left != nullptr ) {
                q.push( node->left );
            }

            if ( node->right != nullptr ) {
                q.push( node->right );
            }

            currLevelElements.push_back( node );
        }
        treeElements.push_back( currLevelElements );
    }

    for ( int i = 0; i < treeElements.size(); i++ ) {
        for ( int j = 0; j < treeElements[ i ].size(); j++ ) {

            if ( j == treeElements[ i ].size()-1 ) {
                treeElements[ i ][ j ]->next = nullptr;
            } else {
                treeElements[ i ][ j ]->next = treeElements[ i ][ j+1 ];
            }
        }
    }

    return root;
}

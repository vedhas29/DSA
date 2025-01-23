
#include <iostream>
#include "binary_tree.h"
#include "binary_tree.cpp"

using namespace std;

int main() {
    Node* root = new Node();
    // root = root->createNode( 5 );
    Node* n = root;
    // n->insertNode( 2 );
    // n->printTree( root );

    cout << "insert elements in tree = ";
    int data = 0;
    for ( int i = 0; i < 5 ; i++ ) {
        cin >> data;
        n->insertNode( data );
    }
    
    n->printTree( root );
    std::cout << "\n pre-order traversal = ";
    n->preOrder( root );
    
    std::cout << "\n in-order traversal = ";
    n->inOrder( root );

    std::cout << "\n post-order traversal = ";
    n->postOrder( root );

    std::vector < std::vector < int >> treeElements;
    std::cout << "\n performing level-order traversal = ";
    treeElements = n->levelOrder( root );
    
    std::cout << "\nprinting level-order traversal = ";
    n->printLevelOrder( treeElements );

    //to find tree diameter
    int leftSubTree = n->heightOfTree( n->left );
    int rightSubTree = n->heightOfTree( n->right );
    int sumOfHeights = ( leftSubTree + rightSubTree );
    std::cout << "Diameter of tree is = " << max( sumOfHeights, n->getDiameter());
    

    return 0;
}
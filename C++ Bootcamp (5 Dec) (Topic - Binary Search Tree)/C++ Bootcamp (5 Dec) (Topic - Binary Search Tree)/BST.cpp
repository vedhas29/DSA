#include <iostream>
using namespace std;

class BST {
    int data;
	BST *left;
	BST *right;

public:

	BST()
	{
        data = 0;
        left = NULL;
        right = NULL;
	}

	BST(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

	BST* Insert(int value)
    {
	if (!this) {
		return new BST(value);
	}

	if (value > this->data) {
		this->right = this->right->Insert(value);
	}
	else if (value <= this->data){
		this->left = this->left->Insert(value);
	}
	return this;
}

	void Inorder()
    {
        if (this == NULL) {
            return;
        }
	this->left->Inorder();
	cout<<this->data<<" ";
	this->right->Inorder();
    }

    void search(int key)
    {
        if(this == NULL )
        {
            return;
        }else if(this->data == key)
        {
            cout<<"Value found"<<endl;
        }

        if (this->data < key)
            this->right->search(key);
        else
            this->left->search(key);
    }

    int height(BST* node)
    {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
        }
    }

    BST* minElement()
    {
        if(this == NULL || this->left == NULL)
            return this;
        else
            this->left->minElement();
    }

    BST* maxElement()
    {
        if(this == NULL || this->right == NULL)
            return this;
        else
            this->right->maxElement();
    }

    int getData()
    {
        return data;
    }


    BST* deleteNode(int key)
    {
    if (this == NULL)
        return this;

    if (key < this->data)
        this->left = this->left->deleteNode(key);

    else if (key > this->data)
        this->right = this->right->deleteNode(key);

    else {
        // node has no child
        if ((this->left == NULL) && (this->right == NULL))
            return NULL;

        // node with only one child or no child
        else if (this->left == NULL) {
            BST* temp = this->right;
            delete this;
            return temp;
        }
        else if (this->right == NULL) {
            BST* temp = this->left;
            delete this;
            return temp;
        }
        // node with two children: Get the inorder successor
        BST* temp = this->right->minElement();

        // Copy the inorder successor's content to this node
        this->data = temp->data;

        // Delete the inorder successor
        this->right = this->right->deleteNode(temp->data);
    }
    return this;
}

};

int main()
{
	BST *b = new BST(50), *root = NULL;
	b->Insert(30);
	b->Insert(20);
	b->Insert(40);
	b->Insert(70);
	b->Insert(60);
	b->Insert(80);

	b->Inorder();

	b->search(63);
	int x = b->height(b);
	cout<<endl<<"Height = "<<x<<endl;

	BST * minNode = b->minElement();
	cout<<"Min value = "<<minNode->getData()<<endl;

	BST * maxNode = b->maxElement();
	cout<<"Max value = "<<maxNode->getData()<<endl;

	b->deleteNode(80);
	b->Inorder();

	return 0;
}


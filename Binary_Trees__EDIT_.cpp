//Original Code by Carlos Moreno
//Edited by Daniel Torres

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* root = nullptr;


void Insert(Node *&nodePtr, Node *&newNode)
{
	if (nodePtr == nullptr) // root == nullptr
	{
		nodePtr = newNode;
	}
	else if (newNode->data <= nodePtr->data)
	{
		Insert(nodePtr->left, newNode);
	}
	else {
		Insert(nodePtr->right, newNode);
	}
}

void InsertNode(int num)
{
	Node* newNode = new Node();
	newNode->data = num;
	newNode->left = newNode->right = nullptr;

	Insert(root, newNode);
}


void InOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	else {
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
}



int main()
{
	InsertNode(31);
	InsertNode(19);
	InsertNode(59);
	InsertNode(7);
	InsertNode(43);

	cout << "In Order: "; InOrder(root);
	cout << endl;

	return 0;
}

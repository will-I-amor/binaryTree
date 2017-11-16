#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int n)
{
	Node* node = new Node;
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void printPreorder(Node* node)
{
	if(node==NULL)
		return;
	cout<<node->data;
	printInorder(node->left);
	printInorder(node->right);
}
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printPreorder(root);
	return 0;
}

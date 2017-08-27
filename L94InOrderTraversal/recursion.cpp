#include <iostream>
#include <vector>
using namespace std;
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
};
Node* newNode(int n){
	Node* node = new Node;
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
/*function*/
void inOrder(Node* root)
{
	if (root){
		if (root->left){inOrder(root->left);}
		cout<<root->data<<endl;
		if (root->right) {inOrder(root->right);}
	}
}
int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	inOrder(root);
	return 0;
}

#include <iostream>
#include <vector>
#include <stack>
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
void inorderTraversal(Node* root)
{
	stack<Node*> mystack;
	//Node* temp = NULL;
	Node* current = NULL;
	if (root){
		mystack.push(root);
		current = mystack.top()->left;
	}
	while (!mystack.empty() || current)//之前错在这里了，没有加||current，循环到根节点的时候stack为空了，直接跳出while loop,导致不能继续行进到右子书
	{
		if (current){
			mystack.push(current);
			current = current->left;
		}
		else
		{
			cout<<mystack.top()->data<<endl;
			current = mystack.top()->right;
			mystack.pop();
		}
	}
}
int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	inorderTraversal(root);
	return 0;
}

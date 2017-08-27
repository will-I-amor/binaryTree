/*fast版本用iteration方法，用两个queue，利用queue的先进先出特性*/
#include <iostream>
#include <vector>
#include <queue>
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
bool isSymmetric(Node* root){
	Node* left;
	Node* right;
	queue<Node*> q1;
	queue<Node*> q2;
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty()&&!q2.empty()){
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();
		if (left==NULL && right==NULL){
			continue;
		}
		if (left==NULL || right==NULL){
			return false;
		}
		if (left->data !=right->data){
			return false;
		}
		if (left && right && left->data==right->data){
			q1.push(left->left);
			q1.push(left->right);
			q2.push(right->right);
			q2.push(right->left);
		}
	}
	return true;
}
int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(3);
	bool flag = false;
	flag = isSymmetric(root);
	if (flag){
		cout<<"This binary tree is is Symmetric"<<endl;
	}
	else{
		cout<<"Not symmetric"<<endl;
	}
	return 0;
}

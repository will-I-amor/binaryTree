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
Node* insert(Node* node, int n){
	if (node == NULL){
		return (newNode(n));
	}
	else{
		if(n<=node->data){
			node->left = insert(node->left, n);
		}
		else{
			node->right = insert(node->right,n);
		}
	}
	return node;
}
void preorder(Node* root){
	if (root==NULL)return;
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}
void rootToLeaf(int val, vector<int>&result, Node* node){
	if (node->left==NULL && node->right==NULL){
		val = val*10+node->data;
		result.push_back(val);
		return;
	}
	val = val*10 + node->data;
	if (node->left!=NULL){
		rootToLeaf(val,result,node->left);
	}
	if (node->right!=NULL){
		rootToLeaf(val,result,node->right);
	}
	if (node==NULL){
		return;
	}
}
int main(){
	Node* root = newNode(9);
	root->right = newNode(8);
	root->left = newNode(7);
	root->right->right = newNode(3);
	root->right->left = newNode(1);
	root->left->left = newNode(6);
	root->left->right = newNode(2);
	//preorder(root);
	int val = 0;
	vector<int>result;
	rootToLeaf(val,result,root);
	cout<<endl;
	int sum = 0;
	for (int i = 0;i<result.size();i++){
		sum += result[i];
	}
	cout<<endl;
	return 0;
}

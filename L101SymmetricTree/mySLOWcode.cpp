/*@this code only beats 1% on Leetcode
*/
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
/*@I used 2 trees to traverse the same tree, to see if it's symmetric
  @if a tree is symmetric, it's also called self-mirrored
*/
bool isSymmetric(Node* root1, Node* root2)
{
	if (root1==NULL && root2==NULL)
		{return true;}
	if (root1==NULL || root2==NULL)
		{return false;}
	if (root1 && root2 && root1->data==root2->data){
		//if(isSymmetric(root1->right,root2->left) && isSymmetric(root1->left,root2->right)){
			return isSymmetric(root1->right,root2->left) && isSymmetric(root1->left,root2->right);
		}
	else{
		return false;
	}
}
bool driver(Node* root){
	Node* root1 = root;
	Node* root2 = root;
	bool flag = false;
	flag = isSymmetric(root1,root2);
	return flag;
}
int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(4);
	root->right->right = newNode(6);
	bool flag = false;
	flag = driver(root);
	if (flag){
		cout<<"This binary tree is is Symmetric"<<endl;
	}
	else{
		cout<<"Not symmetric"<<endl;
	}
	return 0;
}

#include <iostream>
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
int sizeB(Node* node){
	int size = 0;
	if (node!=NULL){
		size = size + 1;
		size = size + sizeB(node->left);
		size = size + sizeB(node->right);
		return size;
	}
	else{
		return size;
	}
	
}
void bottomPB(Node* node){//print out BT in postOrder
	if(node->left == NULL && node->right == NULL){
		cout<<node->data<<endl;
		return;
	}
	else{
		if(node->left != NULL){
			bottomPB(node->left);
		}
		if(node->right!=NULL){
			bottomPB(node->right);
		}
		cout<<node->data<<endl;
	}
}
void printPostorder(Node* node) { 
  if (node == NULL) return;
  // first recur on both subtrees 
  printTree(node->left); 
  printTree(node->right);

  // then deal with the node 
  cout<<node->data<<endl;
} 
int main(){
	Node* node;
	node = insert(node, 2);
	node = insert(node, 3);
	node = insert(node, 1);
	node = insert(node, 4);
	// node = insert(node, 3);
	// node = insert(node, 1);
	//int size = sizeB(node);
	//bottomPB(node);
	printPostorder(node);
	//cout<<size<<endl;
	return 0;
}
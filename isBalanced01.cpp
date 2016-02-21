#include <iostream>
using namespace std;
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
};
TreeNode* newNode(int n){
	TreeNode* node = new TreeNode(n);
	node->val = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
TreeNode* insert(TreeNode* node, int n){
	if (node == NULL){
		return (newNode(n));
	}
	else{
		if(n<=node->val){
			node->left = insert(node->left, n);
		}
		else{
			node->right = insert(node->right,n);
		}
	}
	return node;
}
int checkLength(TreeNode* root)
    {
        if(root == NULL){ return 0;}
        //int leftResult, rightResult;
        int leftResult = checkLength(root->left);
     	if(leftResult == -1){return -1;}
     	int rightResult = checkLength(root->right);
     	if(rightResult == -1){return -1;}
     	int differLength = rightResult>leftResult?rightResult - leftResult:leftResult - rightResult;
     	if(differLength > 1){return -1;}
     	else{ return differLength = (rightResult>leftResult?rightResult - leftResult:leftResult - rightResult)+1;}
}
bool isBalanced(TreeNode* root) {
        if(root == NULL){return true;}
        int result = checkLength(root);
        if(result != -1){return true;}
        else{return false;}
}
int main(){
	TreeNode* node = NULL;
	node = insert(node, 2);
	// node = insert(node, 3);
	// node = insert(node, 1);
	// node = insert(node, 10);
	// node = insert(node, 8);
	// node = insert(node, 9);
	bool flag = isBalanced(node);
	cout<<flag<<'\n';
	return 0;
}







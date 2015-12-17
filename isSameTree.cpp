#include <iostream>
using namespace std;
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	//TreeNode(int x): val(x),left(NULL),right(NULL){}
};
TreeNode* newNode(int n){
	TreeNode* node = new TreeNode;
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
bool isSameTree(TreeNode* p, TreeNode* q){
	bool flag = true;
	if(q == NULL && p!=NULL){flag = false;}
	else if(p == NULL && q!=NULL){flag = false;}
	else if (q == NULL && p == NULL){flag = true;}//传进来的全为NULL
	else if(p->val == q->val && p->left!=NULL && p->right!=NULL){
		flag = isSameTree(p->left, q->left);
		if(flag == false){return flag;}
		flag = isSameTree(p->right,q->right);
	}
	else if (p->val == q->val && p->left == NULL && p->right!=NULL){//左空
		if(q->left!=NULL){flag = false;}
		else{
			flag = isSameTree(p->right, q->right);
		}
	}
	else if (p->val == q->val && p->left != NULL && p->right==NULL){//右空
		if(q->right!=NULL){flag = false;}
		else{
			flag = isSameTree(p->left, q->left);
		}
	}
	else if(p->val != q->val){flag = false;}
	else if(p->val == q->val && p->left == NULL && p->right == NULL){//全空
		if(q->left!=NULL || q->right!=NULL){flag = false;}
		else{
			flag = true;
			//cout<<"断点1： p is: "<<p->val<<" q is: "<<q->val<<endl;
		}
	}
	return flag;
}
int main(){
	TreeNode* node;
	node = insert(node, 2);
	node = insert(node, 3);
	node = insert(node, 1);
	node = insert(node, 1);
	node = insert(node, 8);
	node = insert(node, 9);
	TreeNode* q;
	q = insert(q,2);
	q = insert(q,3);
	q = insert(q,1);
	q = insert(q,1);
	q = insert(q,8);
	bool flag = isSameTree(node, q);
	if(flag == true){
		cout<<"flag is true"<<endl;
	}
	else{
		cout<<"flag is false"<<endl;
	}

	return 0;

}




#include <iostream>
#include <vector>
#include "BFS.h"
using namespace std;
/*struct Node { 
    int data; 
    Node* left; 
    Node* right; 
};*/
Node* addUp(Node* t1,Node* t2,Node* result);
/*Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}*/
/*int height(Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        //compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        //use the larger one
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}*/
Node* addUp(Node* t1,Node* t2,Node* result){
	if (t1==NULL && t2!=NULL){ result = newNode(t2->data);}
	else if (t1!=NULL && t2==NULL){result = newNode(t1->data);}
	else if (t1==NULL && t2==NULL){return NULL;}
	else if (t1!=NULL && t2!=NULL){result= newNode((t1->data)+(t2->data));cout<<((t1->data)+(t2->data))<<"  ";}
	else{
		result->left = addUp(t1->left,t2->left,result->left);
		result->right = addUp(t1->right,t2->right,result->right);
	}
    return result;
}
int main(){
	Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left       = newNode(6);
    Node *root2 = newNode(7);
    root2->left = newNode(6);
    root2->right = newNode(9);
    root2->left->right = newNode(10);
    root2->right->right = newNode(5);
    root2->left->left = newNode(3);
    Node* result = NULL;
    result = addUp(root,root2,result);
    printLevelOrder(result);
    return 0;
}

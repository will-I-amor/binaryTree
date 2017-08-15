#include <iostream>
#include <vector>
using namespace std;
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
};
void printGivenLevel(Node* root, int level);
int height(Node* node);
Node* newNode(int data);
/* Print nodes at a given level */
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
/* Print nodes at a given level */
void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
/* Compute the "height" of a tree -- the number of nodes along the longest path from the root node
    down to the farthest leaf node.
    https://www.youtube.com/watch?v=_SiwrPXG9-g    youtube shows how to get the height
    */
int height(Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
/* Driver program to test above functions*/
/*int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left       = newNode(6);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    
    return 0;
}*/

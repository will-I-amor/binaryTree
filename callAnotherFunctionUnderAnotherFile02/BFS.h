struct Node { 
    int data; 
    Node* left; 
    Node* right; 
};
void printLevelOrder(Node* root);
void printGivenLevel(Node* root, int level);
int height(Node* node);
Node* newNode(int data);

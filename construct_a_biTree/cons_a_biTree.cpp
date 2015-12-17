#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node (int myData,Node* next_ptr = NULL):data(myData),next(next_ptr){}
};


int main(){
	Node* number1 = new Node(1);
	Node* number2 = new Node(2);
	Node* number3 = new Node(3);
	number1->next = number2;
	number2->next = number3;
	Node* node_ptr = number1;
	while (node_ptr != NULL){
		cout<<node_ptr->data;
		if (node_ptr->next != NULL){
			cout<<" ==> ";
		}
		node_ptr = node_ptr->next;
	}
	cout<<endl;
	return 0;

}





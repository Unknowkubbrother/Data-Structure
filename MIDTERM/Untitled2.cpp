#include <iostream>
using namespace std;


class Node{
	public:
		int value;
		Node *next;
		
		Node(int value){
			this->next = NULL;
			this->value = value;
		}
};

void changeValue(Node *test){
	test->value = 10;
}

int main(){
	int *a = new int[2];
	*(a+0) = 3;
	*(a+1) = 2;
	cout<<a[0];
//	Node *l1 = new Node(123);
//	Node *l2 = new Node(234);
//	
//	l1->next = l2;
//	changeValue(l1);
//	Node *temp = l1;
//	while(temp != NULL){
//		cout<<temp->value<<endl;
//		temp = temp->next;
////	}
}

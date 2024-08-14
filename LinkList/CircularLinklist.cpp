#include <iostream>
using namespace std;


class Node{
	public:
		int data;
		Node *next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

class Linklist{
	public:
		Node *head;
		Node *tail;
	
		Linklist(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		void pushBack(int data){
			Node *temp = new Node(data);
			if (!head){
				head = temp;
				tail = temp;
			}else{
				tail->next = temp;
				tail = temp;
				tail->next = head;
			}
		}
		
		void pushFront(int data){
			Node *temp = new Node(data);
			if (!head){
				head = temp;
				tail = temp;
			}else{
				temp->next = head;
				head = temp;
				tail->next = head;
			}
		}
		
		void insertBefore(int data, int pos){
			if (!head){
				pushFront(data);
				return;
			}
			
			if(head->data == pos){
				pushFront(data);
				return;
			}
			
			for(Node *i= head; i->next != head; i=i->next){
				if(i->next->data == pos){
					Node *temp = new Node(data);
					temp->next = i->next;
					i->next = temp;
					return;
				}
			}
			pushBack(data);
		}
		
		void insertAfter(int data, int pos){
			if (!head){
				pushFront(data);
				return;
			}
			
			for(Node *i= head; i->next != head; i=i->next){
				if(i->data == pos){
					Node *temp = new Node(data);
					temp->next = i->next;
					i->next = temp;
					return;
				}
			}
			pushBack(data);
		}
		
		void printList(){
			for(Node *i=head ; i->next != head ;i=i->next){
				cout<<i->data<<" ";
				if(i->next->next == head){
					cout<<i->next->data<<" ";
				}
			}
			cout<<endl;
		}
};

int main(){
	Linklist *l = new Linklist();
	l->pushBack(1);
	l->pushBack(2);
	l->pushBack(3);
	l->pushFront(4);
	l->insertBefore(5,3);
	l->insertAfter(6,2);
	l->insertBefore(7,4);
	l->insertBefore(8,10);
	l->insertAfter(9,10);
	l->insertAfter(10,8);
	l->insertBefore(11,10);
	l->printList();	
}

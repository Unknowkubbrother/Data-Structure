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
			}
		}
		
		void popFront(){
			head = head->next;
		}
		
		void pushFront(int data){
			Node *temp = new Node(data);
			if (!head){
				head = temp;
				tail = temp;
			}else{
				temp->next = head;
				head = temp;
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
			
			for(Node *i= head; i->next != NULL; i=i->next){
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
			
			for(Node *i= head; i != NULL; i=i->next){
				if(i->data == pos){
					Node *temp = new Node(data);
					temp->next = i->next;
					i->next = temp;
					return;
				}
			}
			pushBack(data);
		}
		
		void del(int pos){
			
			if(head->data == pos){
				popFront();
				return;
			}
		
			for(Node *i = head; i->next != NULL ;i=i->next){
				if (i->next->data == pos){
					i->next = i->next->next;
					return;
				}
			}
		}

		void printList(){
			for(Node *i=head;i != NULL; i=i->next){
				cout<<i->data<<" ";
			}
			cout<<endl;
		}
		
};

int main(){
	Linklist *l = new Linklist();
	l->pushBack(1);
	l->pushBack(2);
	l->pushFront(3);
	l->insertBefore(4,2);
	l->insertAfter(5,10);
	l->insertBefore(6,7);
	l->del(6);
	l->printList();
	
}

#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
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
				this->head = temp;
				this->tail = temp;
			}else{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}
		}
		
		void pushFront(int data){
			Node *temp = new Node(data);
			if (!head){
				this->head = temp;
				this->tail = temp;
			}else{
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
		}
		
		void popFront(){
			head->next->prev = NULL;
			head = head->next;
		}
		
		void insertBefore(int data,int pos){
			if (!head){
				pushFront(data);
				return;
			}
			
			if(head->data == pos){
				pushFront(data);
				return;
			}
			
			for(Node *i=head;i != NULL ; i=i->next){
				if (i->data == pos){
					Node *temp = new Node(data);
					temp->prev = i->prev;
					i->prev->next = temp;
					temp->next = i;
					i->prev = temp;
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
			
			for(Node *i=head;i!=NULL;i=i->next){
				if (i->data == pos){
					Node *temp = new Node(data);
					temp->next = i->next;
					temp->prev = i;
					i->next->prev = temp;
					i->next = temp;
					return;
				}
			}
			pushBack(data);
		}
		
		void del(int pos){
			for(Node *i=head;i != NULL ;i=i->next){
				if (i->data == pos){
					i->prev->next = i->next;
					i->next->prev = i->prev;
					return;
				}
			}
		}
				
		void printTo(){
			for(Node *i=head;i !=NULL;i=i->next){
				cout<<i->data<<" ";
			}
			cout<<endl;
		}
		
		void printBack(){
			for(Node *i=tail;i !=NULL;i=i->prev){
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
	l->insertBefore(4,3);
	l->insertAfter(5,4);
	l->insertAfter(6,10);
	l->insertBefore(7,10);
	l->printTo();
	l->printBack();
	l->del(3);
	l->printTo();
	l->printBack();
	
	
	
}

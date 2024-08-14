#include <iostream>
using namespace std;

class Node{
	public:
		int id;
		Node *next;
		
		Node(int id){
			this->id = id;
			this->next = NULL;
		}
};

class Linklist{
	private:
		Node *head;
		Node *tail;
	
	public:
		Linklist(){
		this->head = NULL;
		this->tail = NULL;
		}
		
	void pop_front(){
		head = head->next;
	}
		
	void push_front(int id){
		Node *temp = new Node(id);
		temp->next = head;
		head = temp;
		printList();
	}
		
		
	void insertBefore(int id,int pos){
		if (checkNumber(id)){
			return;
		}
		
		if (head == NULL){
			push_front(id);
			return;
		}
		
		if(head->id == pos){
			push_front(id);
			return;
		}
		
		Node *newList = new Node(id);
		Node *temp = head;
		do{
			if (temp->next->id == pos){
				newList->next = temp->next;
				temp->next = newList;
				printList();
				return;
			}
			temp = temp->next;
		}while(temp->next!=NULL);
		temp->next = newList;
		printList();
	}
	
	
	void insertAfter(int id,int pos){
		if (checkNumber(id)){
			return;
		}
		
		if (head == NULL){
			push_front(id);
			return;
		}

		Node *newList = new Node(id);
		Node *temp = head;
		Node *ptr;
		do{
			if (temp->id == pos){
				newList->next = temp->next;
				temp->next = newList;
				printList();
				return;
			}
			ptr = temp;
			temp = temp->next;
		}while(temp!=NULL);
		ptr->next = newList;
		printList();
	}
	
	void del(int id){
		if (head == NULL){
			return;
		}
		
		if(head->id == id){
			pop_front();
			printList();
			return;
		}
		
		Node *temp = head;
		while(temp->next!=NULL){
			if (temp->next->id == id){
				temp->next = temp->next->next;
				printList();
				break;
			}
			temp = temp->next;
		};
	}
	
	bool checkNumber(int id){
		Node *temp = head;
		while(temp != NULL){
			if (temp->id == id)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	
	void printList(){
		Node *temp = head;
		while(temp != NULL){
			cout<<temp->id<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
};

int main(){
	Linklist l;
	char ch;
	do{
		cin>>ch;
		if(ch=='A'){
			int id;
			int pos;
			cin>>id>>pos;
			l.insertAfter(id,pos);
		}else if (ch=='I'){
			int id;
			int pos;
			cin>>id>>pos;
			l.insertBefore(id,pos);
		}else if (ch=='D'){
			int id;
			cin>>id;
			l.del(id);
		}
	}while(ch!='E');
}


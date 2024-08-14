#include <iostream>
using namespace std;

class Node{
	public:
		int key;
		string value;
		Node *next;
		Node(int key,string value){
			this->key = key;
			this->value = value;
			next = NULL;
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
		
		void pushBack(int key,string value){
			Node *temp = new Node(key,value);
			if (!this->head || !this->tail){
				this->head = temp;
				this->tail = temp;
			}else{
				tail->next = temp;
				tail = temp;
			}
		}
		
		void print(){
			Node *temp = head;
			while(temp != NULL){
				cout<<"("<<temp->key<<","<<temp->value<<")"<<" ";
				temp = temp->next;
			}
		}
		
		void search(int key){
			Node *temp = head;
			while(temp != NULL){
				if (temp->key == key){
					cout<<temp->value<<endl;
					return;
				}
				temp = temp->next;
			}
			cout<<"-"<<endl;
		}
	
};

int main(){
	Linklist l[17]
	char ch;
	do{
		cin>>ch;
		if (ch == 'a'){
			int key;
			string value;
			cin>>key>>value;
			l[key%17].pushBack(key,value);
		}else if (ch == 'p'){
			for(int i=0;i<17;i++){
				if (l[i].head == NULL){
					cout<<"(-1,-)"<<endl;
				}else{
					l[i].print();
					cout<<endl;
				}
			}
		}else if (ch == 's'){
			int key;
			cin>>key;
			l[key%17].search(key);
		}
		
	}while(ch != 'e');
}

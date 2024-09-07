#include <iostream>
using namespace std;

class Node{
	public:
		int key;
		string value;
		Node *next;
		
		Node(){
			this->key = -1;
			this->value = "-";
			this->next = NULL;
		}
		
		Node(int key,string value){
			this->key = key;
			this->value = value;
			this->next = NULL;
		}
};

class separate_chaining{
	public:
		int n;
		Node *hash_table;
		
		separate_chaining(int n){
			this->hash_table = new Node[n];
			this->n = n;
		}
		
		void add(int key,string value){
			if (hash_table[key%n].key == -1){
				hash_table[key%n].key = key;
				hash_table[key%n].value = value;
				hash_table[key%n].next = NULL;
			}else{
				Node *temp = hash_table+(key%n);
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = new Node(key,value);
			}
		}
		
		void print(){
			for(int i=0;i<n;i++){
				Node *temp = hash_table+i
				while(temp != NULL){
					cout<<"("<<temp->key<<","<<temp->value<<")"<<" ";
					temp = temp->next;
				}
				cout<<endl;
			}
		}
		
		void search(int key){
			Node *temp = hash_table+(key%n);
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
	separate_chaining l(17);
	char ch;
	do{
		cin>>ch;
		if (ch == 'a'){
			int key;
			string value;
			cin>>key>>value;
			l.add(key,value);
		}else if (ch == 'p'){
			l.print();
		}else if (ch == 's'){
			int key;
			cin>>key;
			l.search(key);
		}
		
	}while(ch != 'e');
}

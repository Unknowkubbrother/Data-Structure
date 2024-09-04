#include <iostream>
using namespace std;

class Node {
	public:
		int value;
		Node *next;
		
		Node(int v){
			value = v;
			next = NULL;
		}
};

void insert_Front(Node **head, int value){
	Node *new_node = new Node(value);
	new_node->next = *head;
	*head = new_node;
}

Node* insert_Front_2(Node* head, int value){
	Node *new_node = new Node(value);
	new_node->next = head;
	return new_node;
}

void insert_Last(Node **head, Node **tail, int value){
	Node*new_node = new Node(value);
	if (*tail != NULL){
		(*tail)->next = new_node;
	} else {
		*head = new_node;
	}
	*tail = new_node; 
}

Node* delete_Front(Node **head){
	Node* deleted_node = *head;
	*head = (*head)->next;
	return deleted_node;
}

Node* delete_Last(Node **head, Node **last){
	Node *h = *head;
	Node *del_node = *last;
	for(  ;h !=NULL && h->next!= *last; h=h->next){		
	}
	if (h==NULL){
		*head=NULL;
		*last=NULL;
	} else {
		h->next = NULL;
    	*last = h;
	}
	return del_node;
}

Node* delete_value(Node **head, Node **last, int value){
	Node *h = *head;
	Node *del_node = NULL;
	if (h->value == value){
		del_node = h;
		*head = h->next;
	} else {
		for(  ;h->next !=NULL && h->next->value!= value; h=h->next){		
		}
		
		if (h->next==NULL) {
			cout << value << " NOT existed\n";
			return NULL;
		} else {
			del_node = h->next;
			h->next = del_node->next;	
		}
	}

	return del_node;
}


void insert_after_value(int newValue, int value, 
                        Node *head, Node **tail){
	Node *h = head;
	Node *new_node = new Node(newValue);
	for(  ;h!=NULL && h->value!= value; h=h->next){		
	}
	if (h==NULL) {
		cout << value << " NOT existed. Cannot insert " 
		     << newValue << endl;
		return;
	}
	new_node->next = h->next;
	h->next = new_node;
	if (new_node->next == NULL){
		*tail = new_node;
	}
}


int main(){
	Node *list_head = NULL;
	Node *tail = NULL;
	insert_Last(&list_head, &tail, 1);
	insert_Last(&list_head, &tail, 2);
	insert_Last(&list_head, &tail, 3);
	insert_Last(&list_head, &tail, 4);
	insert_after_value(10, 4, list_head, &tail);
	insert_Last(&list_head, &tail, 5);
	//Node *del_node = delete_value(&list_head, &tail, 5);
	
	for(Node *h = list_head; h!=NULL; h=h->next){	
		cout<<h->value<<" ";
	}
	
	
//	Node *tail = NULL;
//	list_head = insert_Front_2(list_head, 10);
//	list_head = insert_Front_2(list_head, 20);
//	list_head = insert_Front_2(list_head, 30);
//	insert_Last(&list_head, &tail, 10);
//	insert_Last(&list_head, &tail, 20);
//	insert_Last(&list_head, &tail, 30);
//	Node* a= delete_Front(&list_head);
//	for(Node *h = list_head; h!=NULL;h=h->next){	
//		cout<<h->value<<" ";
//	}
//	cout << "\nDeleted node is " << a->value << endl;
	
	return 0;
//	insert_Front(&list_head, 1);
//	insert_Front(&list_head, 2);
//	insert_Front(&list_head, 3);
//  list_head = insert_Front_2(list_head,1);
//	list_head = insert_Front_2(list_head,2);
//	list_head = insert_Front_2(list_head,3);

}

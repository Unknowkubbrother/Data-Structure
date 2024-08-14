#include <iostream>
using namespace std;


class Queue{
	public:
		int *arr;
		int head;
		int tail;
		int size;
	
	Queue(int size){
		this->arr = new int[size];
		this->head = 0;
		this->tail = -1;
		this->size = size;
	}
	
	
	void enqueue(int data){
		if(!full()){
			tail++;
			this->arr[tail] = data;
		}
	}
	
	int dequeue(){
		if (!empty()){
			return this->arr[head++];
		}
		return -1;
	}
	
	
	
	bool full(){
		if (tail == size){
			return true;
		}
		return false;
	}
	
	
	bool empty(){
		if (tail < head){
			return true;
		}
		return false;
	}
	
	void printList(){
			for (int i=head; i <= tail;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	
};

int main(){
	Queue *q = new Queue(8);
	char ch;
	do{
		cin>>ch;
		if(ch == 'e'){
			int num;
			cin>>num;
			q->enqueue(num);
		}
		else if (ch == 'd'){
			cout<<q->dequeue()<<endl;
		}
		else if (ch == 'p') {
			q->printList();
		}else if (ch == 'n'){
			cout<<q->tail+1<<endl;
		}else if(ch == 's'){
			cout<<q->arr[q->head]<<" "<<q->arr[q->tail]<<endl;
		}
	}while(ch != 'x');
	
};

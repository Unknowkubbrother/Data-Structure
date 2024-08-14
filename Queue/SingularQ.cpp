#include <iostream>
using namespace std;


class Queue{
	public: 
		int size;
		int head;
		int tail;
		int *arr;
	
		Queue(int size){
			this->arr = new int[size];
			this->head = 0;
			this->tail = -1;
			this->size = size;
		}
		
		void enqueue(int data){
			if(!full()){
				this->arr[++tail%size] = data;
			}
		}
		
		int dequeue(){
			if (!empty()){
				int temp = this->arr[head%size];
				head++;
				return temp;
			}
		}
		
		
		bool full(){
			if (tail - head >= size -1){
				return 1;
			}
			return 0;
		}
		
		bool empty(){
	        if(head>tail){
	            return 1;
	        }
	        return 0;
	    }
	    
	    int sizeq(){
	    	if(!empty()){
	            return tail-head+1;
	        }
	        return 0;
		}
		
		void printList(){
			for(int i=head;i<=tail;i++){
				cout<<this->arr[i%size]<<" ";
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
			cout<<q->sizeq()<<endl;
		}else if(ch == 's'){
			cout<<q->arr[q->head%q->size]<<" "<<q->arr[q->tail%q->size]<<endl;
		}
	}while(ch != 'x');
	
}

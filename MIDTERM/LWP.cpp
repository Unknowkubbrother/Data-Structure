#include <iostream>
using namespace std;

class Stack{
	public:
		int *arr;
		int size;
		int top;
		Stack(int size){
			this->arr = new int[size];
			this->size = size;
			this->top = -1;		
		}
		
		void push(int data){
			if(!full()){
				this->arr[++this->top] = data;
			}else{
				cout<<"full"<<endl;
			}
		}
		
		int pop(){
			if(!empty()){
				return this->arr[this->top--];
			}
			return -1;
		}
		
		
		
		bool full(){
			if (top >= size - 1){
				return true;
			}
			return false;
		}
		
		
		bool empty(){
			(top == -1) ? true : false;
		}
		
		void printlist(){
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<endl;
			}
		}
};

class LWP{
	public:
		int lwp_id;
		int priority;
		LWP *next;
		Stack *stack;
		
		LWP(int lwp_id,int priority,int size){
			this->lwp_id = lwp_id;
			this->next = NULL;
			this->priority = priority;
			this->stack = new Stack(size);
		}
};

int main(){
	Stack *s = new Stack(2);
	s->push(1);
	s->push(2);
	s->printlist();
	
//	LWP *l1 = new LWP(1,0,5);
//	LWP *l2 = new LWP(2,5,5);
//	LWP *l3 = new LWP(3,3,5);
//	
//	l1->next = l2;
//	l2->next = l3;
//	
//	LWP *temp = l1;
//	while(temp != NULL){
//		cout<<temp->lwp_id<<" "<<temp->priority<<endl;
//		temp = temp->next;
//	}
}

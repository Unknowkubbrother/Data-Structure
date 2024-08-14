#include <iostream>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		int *arr;
		Stack(int size){
			this->size = size;
			this->top = -1;
			this->arr = new int[size];
		}		
		
		bool full(){
			if (top > size){
				return true;
			}
			return false;
		}
		
		
		void push(int data){
			if (!full()){
				top++;
				this->arr[top] = data;
			}
		}
		
		int pop(){
			if (!empty()){
				return this->arr[top--];
			}
			return -1;
		}
		
		bool empty(){
			if (top == -1){
				return true;
			}
			return false;
		}
		
		void printlist(){
			for(int i=0;i<=top;i++){
				cout<<this->arr[i]<<" ";
			}
			cout<<endl;
		}
		
};

int main(){
	Stack *s = new Stack(7);
	char ch;
	do{
		cin>>ch;
		if (ch == 'U'){
			int num;
			cin>>num;
			s->push(num);
		}else if(ch == 'T'){
			cout<<s->arr[s->top]<<endl;
		}else if (ch == 'P'){
			s->printlist();
		}else if (ch == 'N'){
			cout<<s->top+1<<endl;
		}else if (ch == 'O'){
			cout<<s->pop()<<endl;
		}
		
	}while(ch != 'X');
}

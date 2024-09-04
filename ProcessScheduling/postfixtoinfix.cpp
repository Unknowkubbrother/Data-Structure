#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		char *arr;
		Stack(int size){
			this->size = size;
			this->top = -1;
			this->arr = new char[size];
		}		
		
		bool full(){
			if (top >= size - 1){
				return true;
			}
			return false;
		}
		
		
		void push(char data){
			if (!full()){
				top++;
				this->arr[top] = data;
			}
		}
		
		char pop(){
			if (!empty()){
				return this->arr[top--];
			}
			return '-1';
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
	
}

#include <iostream>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		char *arr;
        Stack(int size) {
			this->size = size;
			this->top = -1;
			this->arr = new char[size];
		}
		
		void push(char data){
			if(!full()){
				top++;
				this->arr[top] = data;
			}
		}
	
		void pop(){
			if(!empty()){
				top--;
			}
			return;
		}
		
		
		bool full(){
			if (top > size){
				return true;
			}
			return false;
		}
		
		bool empty(){
			if (top == -1){
				return true;
			}
			return false;
		}
};

int main()
{
	Stack *s = new Stack(7);
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if (str[i] == '('){
			s->push(str[i]);
		}else if (str[i] == ')'){
			if (s->empty()){
				cout<<"Error";
				return 0;
			}
			s->pop();	
		}
	}
	if (s->empty()){
		cout<<"Pass";
		return 0;
	}
	cout<<"Error";
	return 0;
}

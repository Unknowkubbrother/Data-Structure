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


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
    	return 3;
    return 0;
}

int main(){
	string text;
	getline(cin,text);
    string result;
    Stack *s = new Stack(text.length());
    for(int i=0;i<text.length();i++){
    	char c = text[i];
    	if(c == '('){
    		s->push(c);
    	}else if (c == ')'){
    		while(!(s->empty())){
    			if(s->arr[s->top] != '('){
    				result += s->pop();
				}else{
					s->pop();
					break;
				}
			}
		}else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
    		while(!(s->empty()) && precedence(s->arr[s->top]) >= precedence(c)){
    			result += s->pop();
			}
			s->push(c);
		}else{
			result += c;
		}
	}
	while(!s->empty()){
		if (s->arr[s->top] != '(' && s->arr[s->top] != ')'){
			result+=s->pop();
		}else{
			s->pop();
		}
	}
	cout<<result<<endl;
	
}

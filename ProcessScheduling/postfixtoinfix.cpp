#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Stack{
	public:
		int size;
		int top;
		string *arr;
		Stack(int size){
			this->size = size;
			this->top = -1;
			this->arr = new string[size];
		}		
		
		bool full(){
			if (top >= size - 1){
				return true;
			}
			return false;
		}
		
		
		void push(string data){
			if (!full()){
				top++;
				this->arr[top] = data;
			}
		}
		
		string pop(){
			if (!empty()){
				return this->arr[top--];
			}
			return "-1";
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
	string text;
	getline(cin,text);
	string resultMain;
	char lastop;
    Stack *s = new Stack(text.length());
    for(int i=0;i<text.length();i++){
    	string c;
    	c += text[i];
    	if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^"){
    			string result;
    			string temp = s->pop();
    			result += "(";
    			result += s->pop();
    			result += c;
    			result += temp;
    			result += ")";
    			s->push(result);
		}else{
			s->push(c);
		}
	}
	while(!s->empty()){
		resultMain+=s->pop();
	}
	cout<<resultMain<<endl;
}

#include <iostream>
#include <stack>
using namespace std;

int pre(char op){
	if (op == '+' || op == '-'){
		return 1;
	}else if (op == '*' || op == '/'){
		return 2;
	}else if (op == '^'){
		return 3;
	}
	return 0;
}

int main(){
	string text;
	stack<char> s;
	getline(cin,text);
	string result;
	for(int i=0;i<text.length();i++){
		if(text[i] == '('){
			s.push(text[i]);
		}else if(text[i] == ')'){
			while(!s.empty()){
				if (text[i] != '('){
					result += s.top();
					s.pop();
				}else{
					s.pop();
					break;
				}
			}
		}else if(text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/' || text[i] == '^'){
			while(!s.empty() && pre(text[i]) <= pre(s.top())){
				result+= s.top();
				s.pop();
			}
			s.push(text[i]);
		}else{
			result+=text[i];
		}
	}
	
	while(!s.empty()){
		result+=s.top();
		s.pop();
	}
	cout<<result<<endl;
}

#include <iostream>
#include <stack>
using namespace std;

int main(){
	string text;
	stack<char> st;
	getline(cin,text);
	int count = 0;
	for(int i=0;i<text.length();i++){
		if (i == 0 && (text[i] == '>' || text[i] == '}' || text[i] == ']' || text[i] == ')')){
			break;
		}
		else if(text[i] == '(' || text[i] == '{' || text[i] == '['){
			st.push(text[i]);
		}else if(text[i] == '<' && text[i+1] == '<'){
			st.push('*');
			i++;
		}else if(text[i] == '<'){
			st.push('<');
		}else if(text[i] == ')' && !st.empty() && st.top() == '('){
			count++;
			st.pop();
		}else if(text[i] == '}' && !st.empty() && st.top() == '{'){
			count++;
			st.pop();
		}else if(text[i] == ']' && !st.empty() && st.top() == '['){
			count++;
			st.pop();
		}else if(text[i] == '>' && text[i+1] == '>' && !st.empty() && st.top() == '*'){
			i++;
			count++;
			st.pop();
		}else if(text[i] == '>' && !st.empty() && st.top() == '<'){
			count++;
			st.pop();
		}
	}
	
	if(!st.empty() || count == 0){
		cout<<"Not matched"<<endl;
		cout<<count<<" matched"<<endl;
	}else{
		cout<<count<<" matched"<<endl;
	}
}


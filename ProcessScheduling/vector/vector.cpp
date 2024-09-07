#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> *v){
	for(int i=0;i<v->size();i++){
		cout<<v->at(i)<<endl;
	}
}

int main(){
	vector<int> v;
	int index = 1;
	v.push_back(1);
	v.erase(v.begin());
	v.insert(v.begin()+index,2);
	print(&v);
}

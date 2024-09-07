#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class process{
	public:
		int id;
		int at;
		int st;
		
		process(){
			
		}
		
		
		process(int id,int at,int st){
			this->id = id;
			this->at = at;
			this->st = st;
		}
};

bool comparesort(process a,process b){
	return a.at < b.at;
}

int main(){
	int size;
	cin>>size;
	queue<process> q;
	process p[size];
	int totaltime = 0;
	for(int i=0;i<size;i++){
		int id,at,st;
		cin>>id>>at>>st;
		p[i] = process(id,at,st);
		totaltime += st;
	}
	
	sort(p,p+size,comparesort);
	
	int round = 0;
	int i=0;
	while(round < totaltime){
		if(!q.empty()){
			process temp = q.front();
			q.pop();
			
			for(int j=0;j<4;j++){
				if(temp.st > 0){
					cout<<temp.id<<" : "<<temp.st<<endl;
					temp.st--;
					round++;
				}
			}
			
			while(i < size && p[i].at <= round){
				q.push(p[i]);
				i++;
			}
			
			if(temp.st > 0){
				q.push(temp);
			}
		}else{
			while(i < size && p[i].at <= round){
				q.push(p[i]);
				i++;
			}
		}
	}
	
	
}

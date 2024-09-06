#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class process{
	public:
		int id;
		int at;
		int st;
		
		process(){}
		
		process(int id,int at,int st){
			this->id = id;
			this->at = at;
			this->st = st;	
		}

};

bool comparesortAt(process a,process b){
	return a.at < b.at;
}

bool comparesortSt(process a,process b){
	return a.st < b.st;
}

int main(){
	int size;
	cin>>size;
	int totaltime;
	vector<process> q;
	process p[size];
	for(int i=0;i<size;i++){
		int id,at,st;
		cin>>id>>at>>st;
		p[i] = process(id,at,st);
		totaltime += st;
	}
	
	sort(p,p+size,comparesortAt);
	int round = 0;
	int i=0;
	q.push_back(p[0]);
	i++;
	while(round < totaltime){
		if(!q.empty()){
			sort(q.begin(),q.end(),comparesortSt);
			process temp = q[0];
			q.erase(q.begin());
			for(int j = temp.st ;j > 0;j--){
				cout<<temp.id<<":"<<temp.st<<endl;
        		temp.st--;
        		round++;
			}
			
			while(i < size && p[i].at <= round){
				q.push_back(p[i]);
				i++;
			}
			
		}
		
	}
}

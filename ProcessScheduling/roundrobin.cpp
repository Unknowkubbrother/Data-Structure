#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class process{
	public:
		int at;
		int st;
		int id;
		
		process() {
		}
	
	    process(int id, int at, int st) {
	        this->id = id;
	        this->at = at;
	        this->st = st;
	    }
};

bool compareSort(process a, process b) {
    return a.at < b.at;
}

int main(){
	int size;
	int serviceTimeAll = 0;
	int qq;
	cin>>size>>qq;
	process p[size];
	queue<process> q;
	for(int i=0;i<size;i++){
		int id, at, st;
        cin >> id >> at >> st;
        p[i] = process(id, at, st);
        serviceTimeAll += st;
	}
	
	sort(p, p + size, compareSort);
	
	int round = 0;
	q.push(p[0]);
	p[0].at = -1;
	
	while(round <= serviceTimeAll){
		while(!q.empty()){
			process temp = q.front();
			q.pop();
			
			for(int j=0;j<qq;j++){
				if(temp.st > 0){
					cout<<"round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
			}
			
			for(int i=0;i<size;i++){
				if (p[i].at <= round && p[i].at != -1){
					q.push(p[i]);
					p[i].at = -1;
				}
			}
			
			if(temp.st > 0){
				q.push(temp);
			}
		}
	}
    
	
}

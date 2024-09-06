#include <iostream>
#include <queue>
#include <math.h>
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
	cin>>size;
	process p[size];
	queue<process> q1;
	queue<process> q2;
	queue<process> q3;
	queue<process> q4;
	queue<process> q5;
	queue<process> q6;
	for(int i=0;i<size;i++){
		int id, at, st;
        cin >> id >> at >> st;
        p[i] = process(id, at, st);
        serviceTimeAll += st;
	}
	
	sort(p, p + size, compareSort);
	
	int round = 0,i = 0;
	q1.push(p[0]);
	i++;
	
	while(round < serviceTimeAll){
		if (!q1.empty()){
			process temp = q1.front();
			q1.pop();
			
			for(int j=0;j<(int)pow(2,0);j++){
				if(temp.st > 0){
					cout<<"q1 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(i==1){
				q1.push(temp);
			}else if (temp.st > 0){
				q2.push(temp);
			}
			
		}else if (!q2.empty()){
			process temp = q2.front();
			q2.pop();
			
			for(int j=0;j<(int)pow(2,1);j++){
				if(temp.st > 0){
					cout<<"q2 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(temp.st > 0){
				q3.push(temp);
			}
		}
		else if (!q3.empty()){
			process temp = q3.front();
			q3.pop();
			for(int j=0;j<(int)pow(2,2);j++){
				if(temp.st > 0){
					cout<<"q3 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(temp.st > 0){
				q4.push(temp);
			}
			
		}else if (!q4.empty()){
			process temp = q4.front();
			q4.pop();
			for(int j=0;j<(int)pow(2,3);j++){
				if(temp.st > 0){
					cout<<"q4 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(temp.st > 0){
				q5.push(temp);
			}
			
		}else if (!q5.empty()){
			process temp = q5.front();
			q5.pop();
			for(int j=0;j<(int)pow(2,4);j++){
				if(temp.st > 0){
					cout<<"q5 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(temp.st > 0){
				q6.push(temp);
			}
			
		}else if (!q6.empty()){
			process temp = q6.front();
			q6.pop();
			for(int j=0;j<(int)pow(2,5);j++){
				if(temp.st > 0){
					cout<<"q6 round "<<round<<" - "<<round+1<<" "<<temp.id<<" : "<<temp.st<<endl;
					round++;
					temp.st--;
				}
				
				if(p[i].at == round){
					q1.push(p[i]);
					i++;
				}
				
			}
			
			if(temp.st > 0){
				q6.push(temp);
			}
		}
	}
	
	
	return 0;
}

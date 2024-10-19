#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Graph{
	public:
		int size;
		vector< vector<int> > adjList;
		
		Graph(int size){
			this->size = size;
			adjList.resize(size);
			for(int i=0;i<size;i++){
				adjList[i].resize(size);
			}
		}
		
		void add(int src,int dest,int weight){
			adjList[src][dest] = weight;
		}
		
		
		void btf(int start){
			vector<bool> check(size,false);
			queue<int> q;
			
			q.push(start);
			check[start] = true;
			
			while(!q.empty()){
				int current = q.front();
				q.pop();
				
				cout<<current<<" ";
				for(int dest=0;dest<size;dest++){
					if (adjList[current][dest] > 0 && check[dest] == false){
						check[dest] = true;
						q.push(dest);
					}
				}
			}
			
			cout<<endl;
		}
		
		void dtfStart(vector<bool> &check,int current){
			cout<<current<<" ";
			check[current] = true;
			
			for(int dest= 0;dest<size;dest++){
				if (adjList[current][dest] > 0 && check[dest] == false){
					dtfStart(check,dest);
				}
			}
		}
		
		void dtf(int start){
			vector<bool> check(size,false);
			dtfStart(check,start);
		}
	
};

int main(){
	int size;
	cin>>size;
	Graph *g = new Graph(size);
	char ch;
	do{
		cin>>ch;
		if (ch == 'e'){
			int src,dest,weight;
			cin>>src>>dest>>weight;
			g->add(src,dest,weight);
		}
		else if (ch == 'b'){
			int start;
			cin>>start;
			g->btf(start);
		}else if (ch == 'd'){
			int start;
			cin>>start;
			g->dtf(start);
		}
	}while(ch != 'q');
	return 0;
}

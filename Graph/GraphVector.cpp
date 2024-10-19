#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	public:
		int numVertex;
		vector< vector<int> > adjList;
		
		Graph(int count){
			numVertex = count;
			adjList.resize(count);
			for(int i = 0;i<adjList.size();i++){
				adjList[i].resize(count);
			}
		}
		
		void addEdge(int src,int dest,int weight){
			adjList[src][dest] = weight;
		}
		
		void btf(int start){
			vector<bool> visited(numVertex, false);
			queue<int> q;
			
			visited[start] = true;
			q.push(start);
			
			while(!q.empty()){
				int current = q.front();
				q.pop();
				
				cout << current <<" ";
				
				for(int i=0;i<numVertex;i++){
					if (adjList[current][i] > 0 && !visited[i]){
						visited[i] = true;
						q.push(i);
					}
				}
			}
			cout<<endl;
		}
		
		void dftStart(int vertex, vector<bool> &visited) {
			visited[vertex] = true;
		    cout << vertex << " ";
		    
		    for(int i=0;i<adjList.size();i++){
		    	if (adjList[vertex][i] > 0 && !visited[i]){
		    		dftStart(i, visited);
				}
			}
		}
		
		void dft(int start){
			vector<bool> visited(numVertex, false);
			dftStart(start,visited);
			cout<<endl;
		}
};


int main(){
	Graph *graph;
	int size;
	cin >> size;
	graph = new Graph(size);
	char ch;
	do {
		cin >> ch;
		if (ch == 'e') {
			int src, dest, weight;
			cin >> src >> dest >> weight;
			graph->addEdge(src, dest, weight);
		} else if (ch == 'b') {
			int startVertex;
			cin >> startVertex;
			graph->btf(startVertex);
		} else if (ch == 'd') {
			int startVertex;
			cin >> startVertex;
			graph->dft(startVertex);
		}
		else if (ch == 's') {
		}
	} while (ch != 'q');
	
	return 0;
	
}

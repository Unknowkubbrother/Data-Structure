#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node{
	public:
		int dest;
		int weight;
		Node *next;
		
		Node(int dest,int weight){
			this->dest = dest;
			this->weight = weight;
			this->next = NULL;
		}
};

bool compare(Node *a,Node *b){
	return a->dest < b->dest;
}

class Graph{
	public:
		vector< vector<Node*> > adjList;
		int size;
		
		Graph(int size){
			this->size = size;
			adjList.resize(size);
		}
		
		void add(int src,int dest,int weight){
			Node *temp = new Node(dest,weight);
			adjList[src].push_back(temp);
			sort(adjList[src].begin(),adjList[src].end(),compare);
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
				for(int i=0;i<adjList[current].size();i++){
					Node *temp = adjList[current][i];
					if ( temp->weight > 0 && !check[temp->dest]){
						check[temp->dest] = true;
						q.push(temp->dest);
					}
				}
				
			}
			cout<<endl;	
		}
		
		void dtfstart(vector<bool> &check, int current){
			cout<<current<<" ";
			check[current] = true;
			
			for(int i=0;i<adjList[current].size();i++){
					Node *temp = adjList[current][i];
					if ( temp->weight > 0 && !check[temp->dest]){
						dtfstart(check,temp->dest);
					}
			}
		}
		
		void dtf(int start){
			vector<bool> check(size,false);
			dtfstart(check,start);
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
			graph->add(src, dest, weight);
		} else if (ch == 'b') {
			int startVertex;
			cin >> startVertex;
			graph->btf(startVertex);
		}
		 else if (ch == 'd') {
			int startVertex;
			cin >> startVertex;
			graph->dtf(startVertex);
		}
		else if (ch == 's') {
		}
	} while (ch != 'q');
	
	return 0;
	
}

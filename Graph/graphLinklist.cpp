#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Pair{
	public:
		int dest,weight;
		
		Pair(){
			
		}
		
		Pair(int d,int w){
			dest = d;
			weight = w;
		}
};


class Node{
	public:
		int dest;
		int weight;
		Node *next;
		
		Node() {}
		
		Node(int d, int w) {
			this->dest = d;
			this->weight = w;
			this->next = NULL;
		}
};

bool compare(Pair a , Pair b){
	return  a.dest < b.dest;
}

class Linklist{
	public:
		Node *head;
		Node *tail;
	
		Linklist() {
			this->head = NULL;
			this->tail = NULL;
		}
		
		void push_back(int dest, int weight) {
			Node *temp = new Node(dest, weight);
			if (!head) {
				head = temp;
				tail = temp;
			} else {
				tail->next = temp;
				tail = temp;
			}
		}
		
		void sort() {
        	vector<Pair> nodes;
	        Node *temp = head;
	
	        while (temp != NULL) {
	            nodes.push_back(Pair(temp->dest,temp->weight));
	            temp = temp->next;
	        }
	
	         std::sort(nodes.begin(), nodes.end(),compare);
	
	        head = tail = NULL;
	        for (int i = 0; i < nodes.size(); i++) {
			    push_back(nodes[i].dest, nodes[i].weight);
			}
    	}
		
};

class Graph{
	public:
		int numVertices;
		vector<Linklist> adjList;
		bool directed;
		
		Graph(int v) {
			numVertices = v;
			adjList.resize(v);
		}
		
		void addEdge(int src, int dest, int weight) {
		    adjList[src].push_back(dest, weight);
		}
		
		void sortAdjList() {
        for (int i = 0; i < numVertices; i++) {
            adjList[i].sort();
	        }
	    }
		
		void bft(int startVertex) {
			vector<bool> visited(numVertices, false);
			queue<int> q;
			
			visited[startVertex] = true;
			q.push(startVertex);
			 
			while (!q.empty()) {
				int current = q.front();
				q.pop();
				
				cout << current << " ";
				
				for (Node *temp = adjList[current].head; temp != NULL; temp = temp->next) {
					if (!visited[temp->dest]) {
						visited[temp->dest] = true;
						q.push(temp->dest);
					}
				}
			}
			cout << endl;
		}
		
		void dfsHelper(int vertex, vector<bool> &visited) {
		    visited[vertex] = true;
		    cout << vertex << " ";

		    for (Node *temp = adjList[vertex].head; temp != NULL ; temp = temp->next) {
		        if (!visited[temp->dest]) {
		            dfsHelper(temp->dest, visited);
		        }
		    }
		}
		
		void dfs(int startVertex) {
		    vector<bool> visited(numVertices, false);
		    dfsHelper(startVertex, visited);
		    cout << endl;
		}
};

int main() {
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
			graph->sortAdjList();
			cin >> startVertex;
			graph->bft(startVertex);
		} else if (ch == 'd') {
			int startVertex;
			graph->sortAdjList();
			cin >> startVertex;
			graph->dfs(startVertex);
		}
	} while (ch != 'q');
	
	return 0;
}


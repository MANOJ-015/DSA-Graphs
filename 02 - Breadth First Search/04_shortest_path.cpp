#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;


class Graph{
	int V;
	list<int> *l;
	
public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	
	void addEdge(int i,int j,bool undir = true){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}
	
	void printAdjList(){
		for(int i=0 ; i<V ; ++i){
			cout << i << " --> ";
			for(int ele : l[i]){
				cout << ele << ",";
			}
			cout << endl;
		}
	}
	
	void bfs(int source,int dest=-1){
		queue<int> q;
		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V]{0};
	
		// add source to the queue.	
		q.push(source);
		visited[source] = true;
		
		while(!q.empty()){
			// print the current node 
			int par = q.front();
			q.pop();
			
			cout << par << " ";
			
			// add the neighbour nodes (childs) to queue
			for(int child : l[par]){
				if(!visited[child]){
					q.push(child);
					dist[child] = dist[par] + 1;
					parent[child] = par;
					visited[child] = true;
					
				}
			}
		}
		
		cout << endl;
		
		
		cout << "Shortest Distance :" << endl;
		
		for(int i=0 ; i<V ; ++i){
			cout << "Shortest Dist of " << i << " is : " << dist[i] << endl;
		}
		cout << endl;
		cout << "Path from Dest to src : " << endl;
		
		int src = source;
		int temp = dest;
		
		while(temp != src){
			cout << temp << " ";
			temp = parent[temp];
		}
		cout << temp << endl;
		
	}
};

int main()
{
	Graph g(7);
	
	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);
	
	g.printAdjList();
	cout << endl;
	
	g.bfs(1,6);
	
	return 0;
}

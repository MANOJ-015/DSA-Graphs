#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


class Graph{
	int V;
	list<int> *l;
	
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	
	// it is directed graph
	void addEdge(int i,int j){
		l[i].push_back(j);
	}
	
	// computing the minimum Distance
	int findMinDistance(int src,int dest){
		vector<bool> visited(V);
		vector<int> distance(V);
		queue<int> q;
		
		q.push(src);
		visited[src] = true;
		
		while(!q.empty()){
			int par = q.front();
			q.pop();
			
			for(int child : l[par]){
				if(!visited[child]){
					q.push(child);
					visited[child] = true;
					distance[child] = distance[par] + 1;
				}
			}
		}
		
		return distance[dest];
		
	}		
		
};

int min_dice_throws(int n,vector<pair<int,int> > &snakes, vector<pair<int,int> > &ladders){
       unordered_map<int,int> m;
       
       for(auto pr : snakes){
            int s = pr.first;
            int e = pr.second;
            m[s] = e - s;
       }
       
       for(auto pr : ladders){
       		int s = pr.first;
       		int e = pr.second;
       		m[s] = e - s;
       }
       // created a graph
       Graph g(n+1);
       
       // add edges to the graph
       for(int i=1 ; i<n ; ++i){
       		for(int dice = 1 ; dice <= 6 ; ++dice){
       			int node = i + dice;
       			node = node + m[node];
       			if(node <= n){
       				g.addEdge(i,node);
       			}
       		}
       }
       
       return g.findMinDistance(1,n);
       
       
}

int main()
{
	vector<pair<int,int>> ladders = {{2,15},{5,7},{9,27},{18,29},{25,35}};
	vector<pair<int,int>> snakes = {{17,4},{20,6},{34,12},{24,16},{32,30}};

	int n = 36;
	
	cout << min_dice_throws(n,snakes,ladders);
	
	return 0;
}

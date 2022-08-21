// dijkstra algorithm
/*

Dijkstra's Algo :
You need to find the shortest distance from the source to all the other nodes in the graph. It can be done over directed or undirected graph. 

First you need to maintain a pq Or set or multiset, then you need to perform bfs over every child of the visited node and update the current distance to the minimum possible one or make no changes. Then simply do this for all the nodes, untill all the nodes are marked visited. 

At the end we have the shortest distance, from source to all the other nodes  in the graph.

*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int N = 1e5+7;
const int INF = 1e9+10;
int n,m;

vector<bool> vis(N);
vector<int> lev(N,INF);
vector<pair<int,int> > graph[N]; // {node,wt}

void dijkstra(int source){
	
	set<pair<int,int> > s; // {dist,node}
	s.insert({0,source});
	lev[source] = 0;
	
	while(s.size() > 0){
		auto nodePair = *s.begin();
		int dist = nodePair.first;
		int node = nodePair.second;
		s.erase(s.begin());
		
		if(vis[node]) continue;
		vis[node] = true;
		
		for(auto childPair : graph[node]){
			int child = childPair.first;
			int wt = childPair.second;
			
			if(lev[node] + wt < lev[child]){
				lev[child] = lev[node] + wt;
				s.insert({lev[child], child});
			}
		}
		
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x,y,wt;
	cin >> n >> m;
	
	for(int i=0 ; i<m ; ++i){
		cin >> x >> y >> wt;
		graph[x].push_back({y,wt});
	}
	
	dijkstra(1);
	
	cout << "source 1 to destination " << n << " distances : \n";
	for(int i=1 ; i<=n ; ++i){
		cout << lev[i] << " ";
	}
	
	
	return 0;
}

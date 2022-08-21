// https://www.codechef.com/problems/REVERSE
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9 + 10;
int n,m;
vector<pair<int,int>> graph[N];
vector<int> level(N,INF);

int bfs(){
	
	deque<int> q;
	q.push_back(1);
	level[1] = 0;
	
	while(!q.empty()){
		int par = q.front();
		q.pop_front();
		
		for(auto childPair : graph[par]){
			int child = childPair.first;
			int wt = childPair.second;
			
			if(level[par] + wt < level[child]){
				level[child] = level[par] + wt;
				if(wt == 0) q.push_front(child);
				if(wt == 1) q.push_back(child);
			}
		}
	}
	
	return level[n] == INF ? -1 : level[n];
}

int main()
{
	int x,y;
	cin >> n >> m;
	
	for(int i=1 ; i<=m ; ++i){
		cin >> x >> y;
		graph[x].push_back({y,0});
		graph[y].push_back({x,1});
	}
	
	cout << bfs();
	
	return 0;
}

// No of Connected Componenets in a Graph.
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/


#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+7;
vector<int> graph[N];
vector<bool> vis(N);

void dfs(int vertex){
	vis[vertex] = true;

	for(int child : graph[vertex]){
		if(!vis[child]){
			dfs(child);
		}
	}
}

int main(){
	int v,e,count = 0;
	cin >> v >> e;

	for(int i=1 ; i<=e ; ++i){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for(int i=1 ; i<=v ; ++i){
		if(!vis[i])
		{
			count++;
			dfs(i);
		}
	}

	cout << count << endl;

	return 0;
}

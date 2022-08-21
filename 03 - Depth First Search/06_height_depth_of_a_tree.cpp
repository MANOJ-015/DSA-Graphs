/*
 * Depth of a Tree: No.of Edges between root node and to particular node
 * Height of a Tree: No.of Max Edges between from a particular node to the leaf node.
 *
 */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

vector<int> graph[N];
vector<int> depth(N),height(N);

void dfs(int vertex,int par=-1){
	
	for(int child : graph[vertex]){
		if(par == child)continue;
		depth[child] = depth[vertex] + 1;
		dfs(child,vertex);
		height[vertex] = max(height[vertex],height[child] + 1);
	}
}


int main()
{
	int n,x,y;
	cin >> n;
	for(int i=1 ; i<=n-1 ; ++i){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	dfs(1);
	
	cout << "Depth Array: " << endl;
	
	for(int i=1 ; i<=n ; ++i){
		cout << depth[i] << " ";
	}
	cout << endl;
	
	
	cout << "Height Array: "<< endl;
	
	for(int i=1 ; i<=n ; ++i){
		cout << height[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}

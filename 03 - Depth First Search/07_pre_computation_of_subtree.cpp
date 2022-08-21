/*
 * Find SubTree Sum and no of even nodes in a subtree
 *
 */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

vector<int> graph[N];
vector<int> noOfEvenNodes(N);
vector<int> subtreeSum(N);

void dfs(int vertex,int par=-1){
	noOfEvenNodes[vertex] += (vertex%2 == 0) ? 1 : 0;
	subtreeSum[vertex] += vertex;
	
	for(int child : graph[vertex]){
		if(par == child)continue;
		dfs(child,vertex);
		subtreeSum[vertex] += subtreeSum[child];
		noOfEvenNodes[vertex] += noOfEvenNodes[child];
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
	
	cout << "Subtree Sum: " << endl;
	
	for(int i=1 ; i<=n ; ++i){
		cout << subtreeSum[i] << " ";
	}
	cout << endl;
	
	cout << "Even Nodes of a SubTee: " << endl;
	for(int i=1 ; i<=n ; ++i){
		cout << noOfEvenNodes[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}

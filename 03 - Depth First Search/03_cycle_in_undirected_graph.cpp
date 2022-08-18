// https://www.interviewbit.com/problems/cycle-in-undirected-graph/

#include<bits/stdc++.h>
using namespace std;

bool dfs(int vertex,int par,vector<int> *graph,vector<bool> &vis){
    
    vis[vertex] = true;
    
    for(int child : graph[vertex]){
        if(!vis[child]){
            bool isCyclePresent = dfs(child, vertex, graph, vis);
            if(isCyclePresent)
                return true;
        }
        else if(child != par){
            return true;
        }
        
    }
    
    return false;
    
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> g[A+1];
    vector<bool> vis(A+1);
  
    for(int i=0 ; i<B.size() ; ++i){
        int x = B[i][0];
        int y = B[i][1];
        
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i=1 ; i<=A ; ++i)
    {
        if(!vis[i]){
            bool ans = dfs(i,-1,g,vis);
            if(ans){
                return true;
            }
        }
    }
    
    return false;
       
}

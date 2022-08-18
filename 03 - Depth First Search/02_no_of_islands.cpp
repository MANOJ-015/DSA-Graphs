#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void dfs(int i,int j, vector<vector<char>> &grid){
      // checking for out of bounds
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != '1')
            return;
        
        grid[i][j] = '2'; // changing 
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j+1,grid);
        dfs(i+1,j-1,grid);
        dfs(i-1,j+1,grid);
        dfs(i-1,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<col ; ++j){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return count;
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}

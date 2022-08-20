 // https://leetcode.com/problems/flood-fill/class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>> &image,int presentColor,int toSetColor){
        
        int n = image.size();
        int m = image[0].size();
        
        // if out of bounds or presentcolor is not same
        if(i<0 || j<0 || i>=n || j>=m || image[i][j] != presentColor){
            return;
        }
        
        image[i][j] = toSetColor;
        
        // running dfs for all it neighbours
        dfs(i,j+1,image,presentColor,toSetColor);
        dfs(i,j-1,image,presentColor,toSetColor);
        dfs(i-1,j,image,presentColor,toSetColor);
        dfs(i+1,j,image,presentColor,toSetColor);
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color){
            return image;
        }
        
        dfs(sr,sc,image,image[sr][sc],color);
        
        return image;
        
    }
};
 
 

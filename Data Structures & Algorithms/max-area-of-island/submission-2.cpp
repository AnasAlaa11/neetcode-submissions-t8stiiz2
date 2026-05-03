class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int& area){
        grid[i][j]=0;
        area++;
        if(i<grid.size()-1&&grid[i+1][j]==1)
            dfs(grid,i+1,j,area);
        if(i>0&&grid[i-1][j]==1)
            dfs(grid,i-1,j,area);
        if(j<grid[i].size()-1&&grid[i][j+1]==1)
            dfs(grid,i,j+1,area);
        if(j>0&&grid[i][j-1]==1)
            dfs(grid,i,j-1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) continue;
                int area=0;
                dfs(grid,i,j,area);
                res=max(res,area);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>&visited,int r,int c){
        for(int n=0;n<4;n++){
            int x=r+dx[n];
            int y=c+dy[n];
            if(x>=0&&y>=0&&x<heights.size()&&y<heights[0].size()&&
                !visited[x][y]&&heights[x][y]>=heights[r][c]){
                    visited[x][y]=true;
                    dfs(heights,visited,x,y);
                }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<bool>> pac_visited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl_visited(rows, vector<bool>(cols, false));
        for(int i=0;i<rows;i++){
            pac_visited[i][0]=true;
            atl_visited[i][cols-1]=true;
            dfs(heights,pac_visited,i,0);
            dfs(heights,atl_visited,i,cols-1);
        }
        for(int j=0;j<cols;j++){
            pac_visited[0][j]=true;
            atl_visited[rows-1][j]=true;
            dfs(heights,pac_visited,0,j);
            dfs(heights,atl_visited,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pac_visited[i][j]&&atl_visited[i][j])res.push_back({i,j});
            }
        }

        return res;
    }
};

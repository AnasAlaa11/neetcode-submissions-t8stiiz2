class Solution {
public:
    #define INF 2147483647
    int dy[4]={1,0,-1,0};
    int dx[4]={0,1,0,-1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        int r,c;
        while(!q.empty()){
            r=q.front().first;
            c=q.front().second;
            q.pop();     
            for(int n=0;n<4;n++){
                int x=r+dx[n];
                int y=c+dy[n];
                if(x>=0&&y>=0&&x<rows&&y<cols&&grid[x][y]==INF){
                    grid[x][y] = grid[r][c] + 1;
                    q.push({x,y});
                }
            }
        }
    }
};

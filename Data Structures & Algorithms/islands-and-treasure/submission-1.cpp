class Solution {
public:
    #define INF 2147483647
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1}; 
    void BFS(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int x,y,a,b;
        while (!q.empty()){
            a=q.front().first;
            b=q.front().second;
            q.pop();
            for(int m= 0; m<4 ; m++){
                x=a+dx[m];
                y=b+dy[m];
                if (x>=0&&x<grid.size()&&y>=0&&y<grid[x].size()){
                    if(grid[x][y]<=grid[a][b]+1) continue;
                    grid[x][y]=grid[a][b]+1;
                    q.push({x,y});
                    
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    BFS(grid,i,j);
                }
            }
        }
    }
};

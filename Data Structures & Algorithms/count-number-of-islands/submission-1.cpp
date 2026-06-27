class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void DFS(vector<vector<char>>& grid,int i , int j){
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        for(int m= 0; m<4 ; m++){
            int a=i+dx[m];
            int b=j+dy[m];
            if (a>=0&&a<grid.size()&&b>=0&&b<grid[a].size())
            DFS(grid,i+dx[m],j+dy[m]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int i=0;
        int j=0;
        int count=0;
        for (int i =0; i<grid.size(); i++){
            for (int j =0; j<grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    count++;
                    DFS(grid,i,j);
                }
            }
        }
        return count;
    }
};

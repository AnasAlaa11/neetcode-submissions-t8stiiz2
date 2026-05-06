class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        queue <pair<int, int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    count++;
                } 
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int r,c,l=q.size();
        while(!q.empty()){
            r=q.front().first;
            c=q.front().second;
            q.pop();
            l--;
            int t_res=res;
            for(int n=0;n<4;n++){
                int x=r+dx[n];
                int y=c+dy[n];
                if(x>=0&&y>=0&&x<rows&&y<cols&&grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y]=2;
                    count--;
                }
            }
            if(l == 0 && !q.empty()){
                res++;
                l = q.size();
            }
        }
        if(count==0) return res;
        return -1;
    }
};

class Solution {
public:
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    void bfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int n=0;n<4;n++){
                int x=r+dx[n];
                int y=c+dy[n];
                if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='O'&&!visited[x][y]){
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O'&&!visited[i][0])
                bfs(board,visited,i,0);
            if(board[i][cols-1]=='O'&&!visited[i][cols-1])
                bfs(board,visited,i,cols-1);  
        }
        for(int j=0;j<cols;j++){
            if(board[0][j]=='O'&&!visited[0][j])
                bfs(board,visited,0,j);
            if(board[rows-1][j]=='O'&&!visited[rows-1][j])
                bfs(board,visited,rows-1,j);  
        }
        for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
                if(visited[i][j]) continue;
                board[i][j]='X';
            }
        }
    }
};

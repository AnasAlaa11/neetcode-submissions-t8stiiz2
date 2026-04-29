class Solution {
public:
    bool check=false;
    void backtraking(vector<vector<char>>& board, string& word,vector<vector<bool>>&visit
                        ,int start,int i,int j){
        if(start==word.length()){
            check=true;
            return;
        }
        if(!check){
            if(i<board.size()-1&&word.at(start)==board[i+1][j]&&!visit[i+1][j]){
                visit[i+1][j]=true;
                backtraking(board,word,visit,start+1,i+1,j);
                visit[i+1][j]=false;
            }
            if(j<board[i].size()-1&&word.at(start)==board[i][j+1]&&!visit[i][j+1]){
                visit[i][j+1]=true;
                backtraking(board,word,visit,start+1,i,j+1);
                visit[i][j+1]=false;
            }
            if(i>0&&word.at(start)==board[i-1][j]&&!visit[i-1][j]){
                visit[i-1][j]=true;
                backtraking(board,word,visit,start+1,i-1,j);
                visit[i-1][j]=false;
            }
            if(j>0&&word.at(start)==board[i][j-1]&&!visit[i][j-1]){
                visit[i][j-1]=true;
                backtraking(board,word,visit,start+1,i,j-1);
                visit[i][j-1]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size(); 
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!=word.at(0)) continue;
                visit[i][j]=true;
                backtraking(board,word,visit,1,i,j);
                visit[i][j]=false;
                if (check) return true;
            }
        }
        return check;
    }
};

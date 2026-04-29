class Solution {
public:
    bool check=false;
    void backtraking(vector<vector<char>>& board, string& word,int start,int i,int j){
        if(start==word.length()){
            check=true;
            return;
        }
        if(!check){
            if(i<board.size()-1&&word.at(start)==board[i+1][j]&&board[i+1][j]!='#'){
                char temp=board[i+1][j];
                board[i+1][j]='#';
                backtraking(board,word,start+1,i+1,j);
                board[i+1][j]=temp;
            }
            if(j<board[i].size()-1&&word.at(start)==board[i][j+1]&&board[i][j+1]!='#'){
                char temp=board[i][j+1];
                board[i][j+1]='#';
                backtraking(board,word,start+1,i,j+1);
                board[i][j+1]=temp;
            }
            if(i>0&&word.at(start)==board[i-1][j]&&board[i-1][j]!='#'){
                char temp=board[i-1][j];
                board[i-1][j]='#';
                backtraking(board,word,start+1,i-1,j);
                board[i-1][j]=temp;
            }
            if(j>0&&word.at(start)==board[i][j-1]&&board[i][j-1]!='#'){
                char temp=board[i][j-1];
                board[i][j-1]='#';
                backtraking(board,word,start+1,i,j-1);
                board[i][j-1]=temp;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!=word.at(0)) continue;
                    char temp=board[i][j];
                    board[i][j]='#';
                    backtraking(board,word,1,i,j);
                    board[i][j]=temp;
                if (check) return true;
            }
        }
        return check;
    }
};

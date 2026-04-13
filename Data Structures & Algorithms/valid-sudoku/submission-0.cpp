class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
        unordered_set<char> rowSet;
        unordered_set<char> colSet;
        unordered_set<char> boxSet;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') {
                    if(rowSet.find(board[i][j]) != rowSet.end()) return false;
                    rowSet.insert(board[i][j]);
                }
                if(board[j][i] != '.') {
                    if(colSet.find(board[j][i]) != colSet.end()) return false;
                    colSet.insert(board[j][i]);
                }
                int r = (i / 3) * 3 + (j / 3);
                int c = (i % 3) * 3 + (j % 3);
                if(board[r][c] != '.'){
                    if(boxSet.find(board[r][c])!=boxSet.end()){
                            return false;
                    }
                    boxSet.insert(board[r][c]);
                }
            }
        }
        return true;   
    }
};


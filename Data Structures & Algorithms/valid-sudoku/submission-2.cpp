class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> r;
        unordered_map<int, unordered_set<char>> c;
        map <pair<int,int>,unordered_set <int>> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if((r[i].count(board[i][j])) ||
                   (c[j].count(board[i][j])) ||
                   (s[{i/3,j/3}].count(board[i][j]))){
                    return false;
                   }
                r[i].insert(board[i][j]);
                c[j].insert(board[i][j]);
                s[{i/3,j/3}].insert(board[i][j]);
            }
        }
        return true;
    }
};

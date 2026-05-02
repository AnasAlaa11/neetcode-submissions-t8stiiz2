class Solution {
public:
    vector<vector<string>> res;
    vector<string> convert(vector<int> &current,vector<string> &h){
        vector<string> c;
        for(int i=0;i<current.size();i++){
            c.emplace_back(h[current[i]]);
        }
        return c;
    }
    bool diagonalCheck(vector<int> &current){
        for(int i=0;i<current.size();i++){
            for(int j=i+1;j<current.size();j++){
                if(current[i]-(j-i)==current[j]||current[i]+(j-i)==current[j]) return false;  
            }
        }
        return true;
    }
    void backtracking(int n,vector<int> &current,vector<bool>&visited,vector<string> &h){
        if(diagonalCheck(current)&&current.size()==n){
            res.emplace_back(convert(current,h));
            return;
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                current.emplace_back(i);
                visited[i]=true;
                backtracking(n,current,visited,h);
                current.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> current;
        vector<string> h;
        vector<bool> visited (n,false);
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(j==i)s+="Q";
                else s+=".";
            }
            h.emplace_back(s);
        }
        backtracking(n,current,visited,h);
        return res;
    }
};

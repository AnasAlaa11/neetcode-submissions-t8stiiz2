class Solution {
public:
    vector<string> res;
    void backtracking(int n,string& current,int open,int close){
        if(current.length()==2*n&&open==n&&open==close){
            res.emplace_back(current);
            return;
        }
        if(open<n){
            string temp=current;
            current+="(";
            backtracking(n,current,open+1,close);
            current=temp;
        }
        if(close<open){
            string temp=current;
            current+=")";
            backtracking(n,current,open,close+1);
            current=temp;
        }
    }
    vector<string> generateParenthesis(int n) {
        string current="";
        backtracking(n,current,0,0);
        return res;
    }
};

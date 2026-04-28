class Solution {
public:
    vector<string> res;
    void backtracking(int n,string& current,int open,int close){
        if(current.length()==2*n&&open==n&&open==close){
            res.emplace_back(current);
            return;
        }
        if(open<=n){
            string temp=current;
            current+="(";
            open++;
            backtracking(n,current,open,close);
            current=temp;
            open--;
        }
        if(close<open){
            string temp=current;
            current+=")";
            close++;
            backtracking(n,current,open,close);
            current=temp;
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        string current="";
        backtracking(n,current,0,0);
        return res;
    }
};

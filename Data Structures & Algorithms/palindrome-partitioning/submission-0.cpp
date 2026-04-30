class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrom(string s){
        if(s=="") return false;
        for(int i=0;i<s.length()/2;i++){
            char c1=s.at(i);
            char c2=s.at(s.length()-i-1);
            if(c1==c2)continue;
            else return false;
        }
        return true;
    }
    void backtracking(string &s,vector<string>&current,int index){
        if(index==s.length()){
            res.emplace_back(current);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrom(s.substr(index,i - index + 1))){
                current.emplace_back(s.substr(index,i - index + 1));
                backtracking(s,current,i+1);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtracking(s,current,0);
        return res;
    }
};

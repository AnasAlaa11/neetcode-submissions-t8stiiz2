class Solution {
public:
    vector<string> res;
    void backtracking(string &current,vector<string> &digits,int start){
        if(current.length()==digits.size()){
            res.emplace_back(current);
            return;
        }
        if(start>=digits.size()) return;
        for(int j=0;j<digits[start].length();j++){
            string temp=current;
            current+=digits[start].at(j);
            backtracking(current,digits,start+1);
            current=temp;
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits=="") return {};
        vector<string> h={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> digit;
        string current="";
        for(int i=0;i<digits.length();i++){
            int n= digits.at(i)-'0';
            digit.emplace_back(h[n]);
        }
        for(int i=0;i<digit[0].length();i++){
            current=digit[0].at(i);
            backtracking(current,digit,1);
        }
        return res;
    }
};

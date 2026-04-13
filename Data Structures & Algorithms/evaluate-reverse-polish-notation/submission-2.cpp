class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> m;
        int res=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                int in=stoi(tokens[i]);
                m.push(in);
            }
            else{
                int x=m.top();
                m.pop();
                int y=m.top();
                m.pop();
                if(tokens[i]=="+") res=y+x;
                else if(tokens[i]=="-") res=y-x;
                else if(tokens[i]=="*") res=y*x;
                else if(tokens[i]=="/") res=y/x;
                m.push(res);
            }
        }
            return m.top(); 
    }
};

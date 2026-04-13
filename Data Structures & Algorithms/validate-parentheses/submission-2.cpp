class Solution {
public:
    bool isValid(string s) {
        stack <char> m;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                m.push(s[i]);
            }
            else{
                if(!m.empty()){
                     if((s[i]==']'&&m.top()=='[')||(s[i]=='}'&&m.top()=='{')||(s[i]==')'&&m.top()=='(')){
                        m.pop();
                        continue;
                    } 
                }
                return false;
            }
        }
        if(m.empty()) return true;

        return false;
        
    }
};

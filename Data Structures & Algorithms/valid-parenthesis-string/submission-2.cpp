class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        int count=0;
        for (int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')' && !st.empty()) st.pop();
            else if(s[i]==')' && st.empty() && !star.empty() && star.top()<i) star.pop();
            else if(s[i]=='*') star.push(i);
            else return false;  
        }
        if(st.empty()) return true;
        else if(star.size()<st.size()) return false ;
        else {
            while(!st.empty()){
                if(star.top()<st.top())return false;
                st.pop();
                star.pop();
            }
        }
        return true;
    }
};

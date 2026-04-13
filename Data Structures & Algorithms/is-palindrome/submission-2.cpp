class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while((i<=(s.size()/2))&&(j>=(s.size()/2))){
            char s1=tolower(s[i]);
            char s2=tolower(s[j]);
            if(((s1>='0'&&s1<='9')||(s1>='a'&&s1<='z'))&&
               ((s2>='0'&&s2<='9')||(s2>='a'&&s2<='z'))){
                if(s1!=s2) return false;
               }
                if(s1<'a'||s1>'z'){
                    i++;
                    continue;
                }
                if(s2<'a'||s2>'z'){ 
                    j--;
                    continue;
                }
                i++;j--;
        }
        return true;
    }
};

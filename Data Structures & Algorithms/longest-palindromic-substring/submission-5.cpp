class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        int l,r;
        string res="";
        pair<int,int> m(-1,-1);
        int temp;
        for(int i=0;i<n;i++){
            l=i-1;
            r=i+1;
            temp=1;
            while(r<n){
                if(s[r]==s[i]&& l==i-1){
                    temp++;
                    r++;
                }
                else if(l >= 0&&s[l]==s[r]){
                    temp+=2;
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
            if(temp>m.first){
                m.first=temp;
                m.second=l + 1;
            }
        }
        res=s.substr(m.second,m.first);
        return res;
    }
};

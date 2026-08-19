class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        if(n==1) return n;
        int l,r;
        int res=0;
        for(int i=0;i<n;i++){
            l=i-1;
            r=i+1;
            while(r<n){
                if(s[r]==s[i]&& l==i-1){
                    res++;
                    r++;
                }
                else if(l >= 0&&s[l]==s[r]){
                    res++;
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
        }
        res=res+n;
        return res;
    }
};

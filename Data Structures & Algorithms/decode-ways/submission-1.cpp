class Solution {
public:
    int numDecodings(string s) {
        int n=s.length()+1;
        if(s[0]=='0') return 0;
        if(n==1) return 1;
        vector<int> dp(n);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<n;i++){
            int temp=stod(s.substr(i-2,2));
            if (s[i-1]=='0'){
                if(temp<10||temp>26) return 0;
                else dp[i]=dp[i-2];
            }
            else if(temp<10||temp>26) dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};

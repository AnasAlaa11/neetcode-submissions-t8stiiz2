class Solution {
public:
    int DP(string text1, string text2,int i,int j,vector<vector<int>>& dp){
        if(i>=text1.length()|| j>=text2.length()) return 0;
        int res=0;
        if(dp[i][j]!=0){
            res=dp[i][j];
        }
        else if(text1[i]==text2[j]){
            res=1+DP(text1,text2,i+1,j+1,dp);
        }
        else{
            res=max(DP(text1,text2,i,j+1,dp),DP(text1,text2,i+1,j,dp));
        }
        dp[i][j] = res;
        return res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector(text2.length(),0));
        return (DP(text1,text2,0,0,dp));
    }
};

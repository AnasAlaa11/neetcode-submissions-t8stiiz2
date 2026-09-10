class Solution {
public:
    int dfs(string s, vector<string>& wordDict,vector<int>& dp,int start){
        if(start==s.length()) return 1;
        if(dp[start]!=0) return dp[start];
        for(int i=0;i<wordDict.size();i++){
            string w=wordDict[i];
            if(start+w.length()<=s.length()){
                if(s.compare(start,w.length(),w) == 0){
                    dp[start]=dfs(s,wordDict,dp,start+w.length());
                    if(dp[start]==1) break;
                }
            }
        }
        if(dp[start]==0){
            dp[start]=-1;
        } 
        return dp[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<int> dp(s.length(),0);
       int res=dfs(s,wordDict,dp,0);
       if (res==1) return true;
       else return false; 
    }
};

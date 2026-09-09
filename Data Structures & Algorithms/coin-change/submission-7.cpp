class Solution {
public:
    int dfs(vector<int>& coins,vector<int>& h, int re, int c){
        if(re == 0) return 0;
        int mini=c;
        for (int i = 0; i<coins.size(); i++){
            int r=re-coins[i];
            if(r>=0)
            {
                if(h[r]<0){
                    mini = min(mini,1+dfs(coins,h,r,c));  
                }
                else mini = min(mini,h[r]+1);
            }
        }
        h[re] = mini;
        return h[re];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> h(amount+1,-1);
        int res=dfs(coins,h,amount,amount+1);
        if(res<0 || res>amount) return -1;
        return res;
    }
};

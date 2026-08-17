class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> c(n,0);
        for(int i=2;i<n;i++){
            c[i]=min(c[i-1]+cost[i-1],c[i-2]+cost[i-2]);
        }
        return min(c[n-1]+cost[n-1],c[n-2]+cost[n-2]);
    }
};
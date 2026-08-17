class Solution {
public:
    int DP(vector<int>& h,int n){
        if(n<=3){
            h[n]=n;
            return n;
        }
        if(h[n]!=0)
            return h[n];
        h[n]=DP(h,n-1)+DP(h,n-2);
        return h[n];
    }
    int climbStairs(int n) {
        vector<int>h(n+1,0);
        return DP(h,n);
    }
};

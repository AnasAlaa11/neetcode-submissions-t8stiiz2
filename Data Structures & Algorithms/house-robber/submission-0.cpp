class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        vector<int> c(n,0);
        for (int i=0;i<n;i++){
            if(i<=1) c[i]=nums[i];
            else if(i==2) c[i]=c[i-2]+nums[i];
            else{
                c[i]=nums[i]+max(c[i-2],c[i-3]);
            }
        }
        return max(c[n-1],c[n-2]);
    }
};
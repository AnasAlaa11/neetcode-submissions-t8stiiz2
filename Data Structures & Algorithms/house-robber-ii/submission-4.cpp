class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int max1,max2;
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        vector<int> c(n,0);
        for(int i=0;i<n-1;i++){
            if(i<=1) c[i]=nums[i];
            else if(i==2) c[i]=nums[i]+c[i-2];
            else{
                c[i]=nums[i]+max(c[i-2],c[i-3]);
            }
        }
        max1=max(c[n-2],c[n-3]);
        for(int i=1;i<n;i++){
            if(i<=2) c[i]=nums[i];
            else if(i==3) c[i]=nums[i]+c[i-2];
            else{
                c[i]=nums[i]+max(c[i-2],c[i-3]);
            }
        }
        max2=max(c[n-1],c[n-2]);
        return max(max1,max2);
    }
};

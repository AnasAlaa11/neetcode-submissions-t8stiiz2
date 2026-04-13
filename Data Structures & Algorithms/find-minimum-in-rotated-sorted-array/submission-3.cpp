class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int r=nums.size()-1;
        int f=nums[0];
        int mini=nums[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<f){
                mini=nums[mid];
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};

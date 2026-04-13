class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_t=0;
        int right_t=nums.size()-1;
        int mini=nums[0];
        int index=-1;
        int first=nums[0];
        int mid_t=-1;
        int t=-1;
        while(left_t<=right_t){
            mid_t=left_t+(right_t-left_t)/2;
            if(nums[(mid_t)]==target) return mid_t;
            else if(nums[mid_t]>=first){
                left_t=mid_t+1;
            }
            else{
                right_t=mid_t-1;
                mini=nums[mid_t];
                t=mid_t;
            }
        }
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[(mid+t)%nums.size()]==target){
                index=(mid+t)%nums.size();
                break;
            }
            else if(nums[(mid+t)%nums.size()]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        return index;
    }
};

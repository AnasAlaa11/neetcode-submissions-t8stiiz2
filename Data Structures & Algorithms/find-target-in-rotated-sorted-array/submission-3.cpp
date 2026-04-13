class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_1=0;
        int right_1=nums.size()-1;
        int index=-1;
        int first=nums[0];
        int mid_1=-1;
        int min_index=-1;
        while(left_1<=right_1){
            mid_1=left_1+(right_1-left_1)/2;
            if(nums[(mid_1)]==target) return mid_1;
            else if(nums[mid_1]>=first){
                left_1=mid_1+1;
            }
            else{
                right_1=mid_1-1;
                min_index=mid_1;
            }
        }
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[(mid+min_index)%nums.size()]==target){
                index=(mid+min_index)%nums.size();
                break;
            }
            else if(nums[(mid+min_index)%nums.size()]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        return index;
    }
};

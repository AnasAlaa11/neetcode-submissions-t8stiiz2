class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow=0;
        int fast=0;
        for(int i=0;i<nums.size();i++){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                slow=0;
                while(slow!=fast){
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return fast;
            }
        }
        return 0;
    } 
};

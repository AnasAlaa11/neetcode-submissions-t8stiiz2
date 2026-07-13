class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0){
                bool flag= false;
                for(int j=i-1;j>=0;j--){
                    if(nums[j]>(i-j)){
                        flag=true;
                        break;
                    } 
                }
                if(!flag) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int goal=nums.size()-1;
        int jumps=0;
        while(goal!=0){
            pair<int,int> maxJump={0,-1};
            for (int i=goal-1;i>=0;i--){
                if(nums[i]+i>=goal && goal-i>maxJump.first){
                    maxJump.first=goal-i;
                    maxJump.second=i;
                }
            }
            goal=maxJump.second;
            jumps++;
        }
        return jumps;
    }
};

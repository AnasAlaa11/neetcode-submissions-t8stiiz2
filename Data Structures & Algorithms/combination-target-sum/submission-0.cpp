class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<int>& current,int sum,int target,int index){
        if(sum>target){
            sum=0;
            return;
        } 
        if(sum==target){
            res.push_back(current);
            return;
        }
        for(int i=index;i<nums.size();i++){
            current.push_back(nums[i]);
            sum+=nums[i];
            backtracking(nums,current,sum,target,i);
            current.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtracking(nums,current,0,target,0);
        return res;
    }
};

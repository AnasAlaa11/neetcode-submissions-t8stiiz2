class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<int>& current,int index){
        res.emplace_back(current);
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            current.emplace_back(nums[i]);
            backtracking(nums,current,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        backtracking(nums,current,0);
        return res;
    }
};

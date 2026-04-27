class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int,int>m;
    void backtracking(vector<int>& nums,vector<int>& current){
        if(current.size()==nums.size()){
            res.emplace_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0) continue;
            current.emplace_back(nums[i]);
            m[nums[i]]--;
            backtracking(nums,current);
            current.pop_back();
            m[nums[i]]++;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        for(int i:nums) m[i]++;
        backtracking(nums,current);
        return res;
    }
};

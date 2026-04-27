class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<int>& current,vector<bool>& visited){
        if(current.size()==nums.size()){
            res.emplace_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            current.emplace_back(nums[i]);
            visited[i]=true;
            backtracking(nums,current,visited);
            current.pop_back();
            visited[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        backtracking(nums, current, visited);
        return res;
    }
};

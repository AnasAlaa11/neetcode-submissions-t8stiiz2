class Solution {
public:
    vector<vector<int>> res;
    void sub(vector<int>& nums,vector<int>& current,int index){
        res.emplace_back(current);
        for(int i=index;i<nums.size();i++){
            current.emplace_back(nums[i]);
            sub(nums,current,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        sub(nums,current,0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int index=0;index<nums.size();index++){
            int l=index+1;
            int r=nums.size()-1;
            while(l<r){
                int temp=nums[index]+nums[l]+nums[r];
                if(nums[index]+nums[l]+nums[r]==0){
                    res.insert({nums[index],nums[l],nums[r]});
                }
                if(temp>0) r--;
                else l++;
            }
        }
        for(auto t:res){
            result.push_back(t);
        }

        return result;
    }
}; 
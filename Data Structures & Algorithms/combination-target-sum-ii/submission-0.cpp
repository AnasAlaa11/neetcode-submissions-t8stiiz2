class Solution {
public:
    vector<vector<int>> res;
    void backtracking(const vector<int>& candidates,vector<int>& current,
            int target,int& sum,int& remain,int index){
                if(sum+remain<target||sum>target) return;
                if(sum==target){
                    res.emplace_back(current);
                    return;
                }
                for(int i=index;i<candidates.size();i++){
                    if(i > index&&candidates[i] == candidates[i-1]) continue;
                    current.emplace_back(candidates[i]);
                    sum+=candidates[i];
                    remain-=candidates[i];
                    backtracking(candidates,current,target,sum,remain,i+1);
                    current.pop_back();
                    sum-=candidates[i];
                    remain+=candidates[i];
                }
            }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        int remain=0;
        int sum=0;
        for(int i=0;i<candidates.size();i++){
            remain+=candidates[i];
        }
        sort(candidates.begin(), candidates.end());
        backtracking(candidates,current,target,sum,remain,0);
        return res;
    }
};

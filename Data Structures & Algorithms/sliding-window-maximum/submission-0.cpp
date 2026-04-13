class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        vector <int> res;
        priority_queue<pair<int, int>> m;
        for(int j=0;j<nums.size();j++){
                m.push({nums[j],j});
                if (j >= k - 1) {
                int i = j - k + 1;
                while (m.top().second < i) {
                    m.pop();
                }
                res.push_back(m.top().first);
            }
        }
        return res;
    }
};

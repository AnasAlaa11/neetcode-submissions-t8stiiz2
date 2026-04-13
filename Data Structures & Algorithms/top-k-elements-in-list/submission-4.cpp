class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> v;
        unordered_map<int , int> um;
        for(auto t: nums){
            um[t]++;
        }

        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto m: um){
            pq.push({m.second,m.first});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
                v.push_back(pq.top().second);
                pq.pop();
        }
        return v;
    }
};

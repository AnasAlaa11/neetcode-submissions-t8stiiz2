class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        multiset <int> ms;
        ms.insert(nums.begin(),nums.end());
        int r=0;
        int h=0;
        vector<int> v;
        unordered_set <int> us;
        us.insert(nums.begin(),nums.end());
        for(int i:us){
            m.insert({i,ms.count(i)});
        }
        while(r<k){
            int j=0;
            for(int i:us){
                if(j<m[i]){
                    j=m[i];
                    h=i;
                }
            }
            r++;
            v.push_back(h);
            m.erase(h);
        }
        return v;
           
    }
};

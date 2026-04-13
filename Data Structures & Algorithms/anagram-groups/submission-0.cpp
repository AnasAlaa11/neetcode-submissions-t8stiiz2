class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for (int i=0;i<strs.size();i++){
            string original=strs[i];
            string sor=strs[i];

            sort(sor.begin(),sor.end());
            mp[sor].push_back(original);
        }
        vector<vector<string>> it;
        for(auto m:mp){
           it.push_back(m.second);
        }
        return it;
    
    
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int i=0;
        int j=0;
        int count=0;
        int maxi=0;
        unordered_set<char> m;
        while(j<s.size()){
            if(!m.count(s[j])){
                m.insert(s[j]);
                count++;
                j++;
            }
            else{
                m.erase(s[i]);
                i++;
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};

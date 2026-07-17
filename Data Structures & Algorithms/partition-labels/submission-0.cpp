class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
        }
        int goal=0;
        int count=0;
        vector<int> res;
        for(int i=0;i<s.length();i++){
            if(i>goal){
                res.push_back(count);
                count=0;
            }
            goal=max(goal,last[s[i]-'a']);
            count++;
        }
        res.push_back(count);
        return res;
    }
};

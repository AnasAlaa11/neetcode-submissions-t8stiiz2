class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0;
        int j=0;
        vector<int> m(26, 0);
        int count=0;
        for(int i=0;i<s1.size();i++){
            m[s1[i]-'a']++;
        }
        while(j<s2.size()){
            m[s2[j]-'a']--;    
            if(m[s2[j]-'a']<0){
                while(m[s2[j]-'a']<0){
                    m[s2[i]-'a']++;
                    i++;
                } 
            }
            if((j-i+1)==s1.size()) return true;
            j++;
        }
        return false;
           
    }
};

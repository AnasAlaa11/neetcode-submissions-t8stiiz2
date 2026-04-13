class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=1;
        int maxi=1;
        string temp;
        temp = s[i];
        if(s.size()==0) return 0;
        while(j<s.size()){
            if((temp.find(s[j]))==string::npos){
                temp+=s[j];
                j++;
            }
            else{
                temp.erase(0,1);
            }
            int size=temp.size();
            maxi=max(maxi,size);
            maxi=max(maxi,size);
        }
        return maxi;
    }
};

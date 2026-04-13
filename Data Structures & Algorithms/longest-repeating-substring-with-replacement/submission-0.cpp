class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxi=0;
        int maxt=0;
        int m[26]={0};
        while(j<s.size()){
                m[s[j]-'A']++;
                for(int x=0;x<26;x++){
                    maxt=max(maxt,m[x]);
                }
                while((j-i+1)-maxt>k){
                    m[s[i]-'A']--;
                    i++;
                }  
            maxi=max(maxi,(j-i+1));
            j++;
        }
        return maxi;
    }
};

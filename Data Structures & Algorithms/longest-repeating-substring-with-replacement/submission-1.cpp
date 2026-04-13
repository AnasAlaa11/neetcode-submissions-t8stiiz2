class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        while(j<s.size()){
            int repeat[26]={0};
            int index=0;
            for(int x=i;x<=j;x++){
                repeat[s[x]-'A']++;
                if(repeat[s[index]-'A']<repeat[s[x]-'A']) index=x;
            }
            if((j-i+1)-repeat[s[index]-'A']>k){
                repeat[s[i]-'A']--;
                i++;
            }
            count=max(count,(j-i+1));
            j++; 
        }
        return count;
    }
};

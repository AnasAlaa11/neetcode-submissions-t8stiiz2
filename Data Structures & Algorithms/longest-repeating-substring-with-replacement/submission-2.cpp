class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        int index=0;
        int repeat[26]={0};
        while(j<s.size()){
            repeat[s[j]-'A']++;
            for(int x=0;x<26;x++){
                index=max(repeat[x],index);
            }
            if((j-i+1)-index>k){
                repeat[s[i]-'A']--;
                i++;
            }
            count=max(count,(j-i+1));
            j++; 
        }
        return count;
    }
};

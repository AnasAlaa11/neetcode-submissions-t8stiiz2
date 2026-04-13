class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int repeat[60]={0};
        int count=INT_MAX;
        int start_index=-1;
        for(int i=0;i<t.size();i++){
            repeat[t[i]-'A']++;
        }
        while(j<s.size()){
            repeat[s[j]-'A']--;
            bool check=true;
            for(int x=0;x<60;x++){
                if(repeat[x]>0){
                    check=false;
                    break;
                }
            }
            while(check&&i<=j){
                int len=j-i+1;
                repeat[s[i]-'A']++;
                if(repeat[s[i]-'A']>0){
                    if(len<count){
                        count=len;
                        start_index=i;
                    }
                    check=false;
                }
                i++;
            }
            j++;
        }
        if (start_index == -1) return "";
        return s.substr(start_index, count);
    }
};

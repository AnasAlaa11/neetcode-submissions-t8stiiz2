class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int i=0;
        int j=i;
        int start_index=-1;
        int count=INT_MAX;
        int m[128]={0};
        string res="";
        for(int i=0;i<t.size();i++){
            m[t[i]]++;
        }
        while(j<s.size()){
            m[s[j]]--;
            bool a=true;
            for(int x=0;x<t.size();x++){
                if(m[t[x]]>0){
                    a=false;
                    break;
                }
            }
            while (a) {
                int current_len = j - i + 1;
                if (current_len < count) {
                    count = current_len;
                    start_index = i;
                }
                m[s[i]]++; 
                if (m[s[i]] > 0) {
                    a = false;
                }
                i++;
            }
            j++;        
        }
        if (start_index == -1) return "";
        return s.substr(start_index, count);
    }
};

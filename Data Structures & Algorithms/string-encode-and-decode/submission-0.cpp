class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(int i=0;i<strs.size();i++){
            int n=strs[i].size();
            string buffer = to_string(n);
            res+=buffer+"*"+strs[i];
        }
        return res;
    }

vector<string> decode(string s) {
    vector<string> res;
    int i=0;
    while(i<s.size()){
        int j=i;
        while(j < s.size() && s[j] != '*') {
            j++;
        }
        if (j == s.size()) break;
        int len = stoi(s.substr(i, j - i));
        i=j+1;
        string word = s.substr(i, len);
        res.push_back(word);
        i+=len;
    }
    return res;
}
};

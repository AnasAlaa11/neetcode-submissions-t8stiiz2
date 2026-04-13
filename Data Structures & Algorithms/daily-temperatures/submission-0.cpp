class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pair<int,int>> m;
        vector <int> res(temperatures.size(),0);
        m.push({temperatures[0],0});
        for(int i=1;i<temperatures.size();i++){
            while(!m.empty()&&m.top().first<temperatures[i]){
                res[m.top().second]=(i-(m.top().second));
                m.pop();
            }
            m.push({temperatures[i],i});
        }
        return res;
    }
};

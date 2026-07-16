class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize !=0) return false;
        unordered_map<int,int> count;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<hand.size();i++){
            count[hand[i]]++;
        }
        for(const auto& pair: count){
            pq.push({pair.first,pair.second});
        }
        stack<pair<int,int>> st;
        while(!pq.empty()){
            for(int i=0;i<groupSize;i++){
                if(pq.empty()) return false;
                int key=pq.top().first;
                int value=(pq.top().second)-1;
                pq.pop();
                if(!pq.empty()&&i!=groupSize-1&&pq.top().first!=key+1) return false;
                if(value>0) st.push({key,value});
            }
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }
        return true;
    }
};

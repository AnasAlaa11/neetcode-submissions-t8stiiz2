class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        priority_queue<pair<int , int>>pq;
        int n=gas.size(); 
        int gain;
        for (int i=0;i<n;i++){
            gain=gas[i]+gas[(i+1)%n]-cost[i];
            pq.push({gain,i});
        }
        while(!pq.empty()){
            int start=pq.top().second;
            pq.pop();
            int tank=gas[start];
            for(int i=1;i<=n;i++){
                tank = tank -cost[(start+i-1)%n];
                if (tank<0) break;
                tank += gas[(start+i)%n];
            }
            if (tank>=0) return start;
        }
        return -1;
    }
};

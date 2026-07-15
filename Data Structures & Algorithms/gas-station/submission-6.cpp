class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(); 
        int tank=0;
        int l=0;
        int r=0;
        int count=0;
        int station=0;
        while(station<n&& count<=n){
            tank=tank+gas[r]-cost[r];
            r=(r+1)%n;
            station++;
            while(tank<0){
                station--;
                tank =tank-gas[l]+cost[l];
                l=(l+1)%n;
                count++;
            }    
        }
        if(station==n) return l;
        return -1;
    }
};

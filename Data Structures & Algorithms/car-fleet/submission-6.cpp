class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        stack <double> time;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        for(int i=position.size()-1;i>=0;i--){
            double t = (double)(target - cars[i].first) / cars[i].second;
            if(time.empty() || t > time.top()){
                time.push(t); 
            }
        }
        return time.size();
    }
};

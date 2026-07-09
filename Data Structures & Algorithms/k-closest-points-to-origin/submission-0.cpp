class Solution {
public:
    double distance(vector<int>& point){
        return pow((pow(point[0],2)+pow(point[1],2)),0.5);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
        for(int i=0;i<points.size();i++){
            double d=distance(points[i]);
            q.push({d,i});
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            int index=q.top().second;
            q.pop();
            res.push_back(points[index]);
        }
        return res;

    }
};

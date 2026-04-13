class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int temp=i;
            int temp1=heights[i];
            while(!s.empty()&&heights[i]<s.top().second){
                temp=s.top().first;
                temp1=s.top().second;
                s.pop();
                maxArea=max(maxArea,(i-temp)*temp1);
            }
            s.push({temp,heights[i]});
        }
        int n=heights.size();
        while(!s.empty()){
            int temp=s.top().first;
            int temp1=s.top().second;
            s.pop();
            maxArea=max(maxArea,(n-temp)*temp1);
        }
        return maxArea;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int A=0;
        for(int i=0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
                int temp=min(heights[i],heights[j])*(j-i);
                if(A<temp){
                    A=temp;
                }
            }
        }
        return A;
    }
};

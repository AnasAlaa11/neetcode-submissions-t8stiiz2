class Solution {
public:
    int maxArea(vector<int>& heights) {
        int A=0;
        int i=0;
        int j=heights.size()-1;
        while(i<j){
            int temp=min(heights[i],heights[j])*(j-i);
            if(A<temp) A=temp;
            if(heights[i]<heights[j]) i++;
            else if(heights[i]>heights[j])j--;
            else if(heights[i+1]>heights[j-1]) j--;
            else i++;
        }
        return A;
    }
};

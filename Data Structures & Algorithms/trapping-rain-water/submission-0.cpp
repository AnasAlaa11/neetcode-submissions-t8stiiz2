class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> max_left(height.size());
        vector <int> max_right(height.size());
        vector <int> mins(height.size());
        int templ=0;
        int tempr=0;
        int res=0;
        for(int i=0;i<height.size();i++){
            max_left[i]=templ;
            if(templ<height[i]){
                templ=height[i];
            }
            max_right[height.size()-i-1]=tempr;
            if(tempr<height[height.size()-i-1]){
                tempr=height[height.size()-i-1];
            }
        }
        for(int i=0;i<height.size();i++){
            mins[i]=min(max_left[i],max_right[i]);
        }
        for(int i=0;i<height.size();i++){
            int temp=mins[i]-height[i];
            if(temp>0){
                res+=temp;
            }
        }
    return res;
    }
};

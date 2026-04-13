class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l_vector=0;
        int r_vector=matrix.size()-1;
        int index=-1;
        while(l_vector<=r_vector){
            int mid_vector=l_vector+(r_vector-l_vector)/2;
            pair<int,int> mid_max_min={matrix[mid_vector][0],matrix[mid_vector][matrix[mid_vector].size()-1]};
            if(target>mid_max_min.second) l_vector=mid_vector+1;
            else if(target<mid_max_min.first) r_vector=mid_vector-1;
            else {
                index=mid_vector;
                break;
            }
        }
        if(index==-1) return false;
        int l=0;
        int r=matrix[index].size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==matrix[index][mid]) return true;
            else if(target>matrix[index][mid]) l=mid+1;
            else r=mid-1;  
        }
        return false;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
    int res=INT_MAX;
    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
    }
    int l=1;
    int r=maxi;
    while(l<=r){
        int mid=l+(r-l)/2;
        int total_hours=0;
        for(int i=0;i<piles.size();i++){
            total_hours+=(piles[i]+mid-1)/mid;
        }
        if(total_hours<=h){
            res=min(res,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return res;
    }
};

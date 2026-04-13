class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int total=nums1.size()+nums2.size();
        int half=total/2;
        int l=0;
        int r=nums1.size();
        while(l <= r){
            int i=l+(r-l)/2;
            int j=half-i;
            double aleft,aright,bleft,bright;
            aleft= (i>0)? nums1[i-1]:INT_MIN;
            aright= (i<nums1.size())?nums1[i]:INT_MAX;
            bleft= (j>0)?nums2[j-1]:INT_MIN;
            bright= (j<nums2.size())?nums2[j]:INT_MAX;
            if(aleft<=bright&&bleft<=aright){
                if(total%2) return min(aright,bright);
                else return (max(aleft,bleft)+min(aright,bright))/2.0;
            }
            else if(aleft>bright) r=i-1;
            else l=i+1;
            
        }
    }
};

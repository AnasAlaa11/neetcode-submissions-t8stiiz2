class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c=1;
        int index=0;
        bool flag=true;
        int zeroCount=0;

        vector<int> res(nums.size(), 0);
         for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                flag=false;
                zeroCount++;
                index=i;
                continue;
            }
            c*=nums[i];
        }
        if(flag){
            for(int i=0;i<nums.size();i++){
                res[i]=c/nums[i];
            }
            return res;
        }
        else if(zeroCount > 1){
             return res;
        }
         res[index]=c;
         return res;
    }
};
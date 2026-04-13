class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=1;
        int max=0;
        while(i<j&&j<prices.size()){
            if(prices[i]>prices[j]){
                i=j;
                j++;
                continue;
            }
            else if(max<(prices[j]-prices[i])){
                max=prices[j]-prices[i];
                j++;
                continue;
            }
            j++;
        }
        return max;
    }
};

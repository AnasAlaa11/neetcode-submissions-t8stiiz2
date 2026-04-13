class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        sort(numbers.begin(),numbers.end());
        while(i<j&& numbers[i]+numbers[j]!=target){
            if(numbers[i]+numbers[j]>target){
                    j--;
                    continue;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
                continue;
            }
        }

        return {i+1,j+1};
    }
};

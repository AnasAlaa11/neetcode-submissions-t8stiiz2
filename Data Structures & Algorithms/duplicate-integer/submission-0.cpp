#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set <int> us;
        us.insert(nums.begin(),nums.end());
        if(us.size()==nums.size()) return false;
        return true;
    }
};
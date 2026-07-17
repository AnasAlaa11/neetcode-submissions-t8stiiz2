class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> count (3,0);
        int x,y,z;
        for (int i=0;i<triplets.size();i++){
            x=triplets[i][0]; y=triplets[i][1]; z=triplets[i][2];
            if(x==target[0]&&y<=target[1]&&z<=target[2])
                count[0]++;
            if(y==target[1]&&x<=target[0]&&z<=target[2])
                count[1]++;
            if(z==target[2]&&x<=target[0]&&y<=target[1])
                count[2]++;
        }
        return (count[0]!=0&&count[1]!=0&&count[2]!=0);
    }
};

class Solution {
public:
    void un(vector<int>&v,int i, int j){
        if(v[i]<v[j]){
            v[i]=v[i]+v[j];
            v[j]=i;
        }
        else{
            v[j]=v[i]+v[j];
            v[i]=j;
        }
    }
    int find(vector<int>&v,int i){
        int x=i;
        while (v[x]>=0){
            x=v[x];
        }
        return x;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<int>ve (n,-1);
        int i=0;
        int u,v;
        while (i<n-1){
            u=edges[i][0];
            v=edges[i][1];
            if(find(ve,u)==find(ve,v))
                return false;
            un(ve,find(ve,u),find(ve,v));
            i++;
        }
        return true;
    }
};

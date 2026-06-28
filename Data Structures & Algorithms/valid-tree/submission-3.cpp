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
    int find(vector<int>& v, int i) {
    if (v[i] < 0) 
        return i;
    return v[i] = find(v, v[i]); 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<int>ve (n,-1);
        int i=0;
        int u,v,a,b;
        while (i<n-1){
            u=edges[i][0];
            v=edges[i][1];
            a=find(ve,u);
            b=find(ve,v);
            if(a==b)
                return false;
            un(ve,a,b);
            i++;
        }
        return true;
    }
};

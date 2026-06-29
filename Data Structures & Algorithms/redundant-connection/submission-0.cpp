class Solution {
public:
    void unionSets(vector<int>&v, int i, int j){
        if(v[i]<v[j]){
            v[i]=v[i]+v[j];
            v[j]=i;
        }
        else{
            v[j]=v[i]+v[j];
            v[i]=j;
        }
    }
    int find(vector<int>&v, int i){
        int x=i;
        while(v[x]>0){
            x=v[x];
        }
        return x;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,-1);
        stack<vector<int>> st;
        int i=0,v,u,a,b;
        while(i<edges.size()){
            u=edges[i][0];
            v=edges[i][1];
            a=find(parent,u);
            b=find(parent,v);
            if(a==b)
                st.push({u,v});
            else
                unionSets(parent,a,b);
            i++;     
        }
        vector<int> res=st.top();
        return res;
    }
};

class Solution {
public:
    void un(vector<int>&v, int i, int j){
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
        while(v[x]>=0){
            x=v[x];
        }
        return x;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> ve(n,-1);
        int i=0,v,u,a,b;
        while(i<edges.size()){
            u=edges[i][0];
            v=edges[i][1];
            a=find(ve,u);
            b=find(ve,v);
            if(a!=b){
                un(ve,a,b);
            }   
            i++;     
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ve[i]<0) c++;
        }
        return c;
    }
};

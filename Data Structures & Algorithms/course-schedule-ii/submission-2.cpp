class Solution {
public:
    vector<int> res;
    unordered_set<int> visit;
    bool dfs(vector<int>& state,vector<vector<int>>& adj,int node){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node]=1;
        for(int n:adj[node]){
            if(!dfs(state,adj,n)) return false;
        }
        state[node]=2;
        if(!visit.count(node)) res.emplace_back(node);
        visit.insert(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state (numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(!dfs(state,adj,i)) return {};
            }
        }
        for(int i=0;i<numCourses;i++){
            if(visit.count(i)) continue;
            res.emplace_back(i);
        }
        return res;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count (26,0);
        priority_queue<pair<int,int>> q;
        queue<pair<int,int>> waiting;
        vector<int> timer (26,0);
        int res=0;
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0)
                q.push({count[i],i});
        }
        while(!q.empty()||!waiting.empty()){
            res++;
            if(!q.empty()){
                int x=(q.top().first)-1;
                int y=q.top().second;
                q.pop();
                if(x>0){
                    timer[y]=n;
                    waiting.push({x,y});
                }
            }
            if(!waiting.empty()){
                int x=waiting.front().first;
                int y=waiting.front().second;
                if(timer[y]==0){
                    q.push({x,y});
                    waiting.pop();
                }   
                for(int i=0;i<26;i++){
                    if(timer[i]!=0)
                        timer[i]--;
                }
            }
        }
        return res;
    }
};

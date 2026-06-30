class Solution {
public:
    bool compare(string w1, string w2){
        int count=0;
        for(int i=0;i<w1.length();i++){
            if(count>1) return false;
            if(w1[i]!=w2[i])
                count++;
        }
        return count==1;
    }
    int BFS(vector<string>& wordList,vector<vector<int>> &adj,string endWord,int start){
        queue<int> q;
        vector<bool> visited (adj.size(),false);
        q.push(start);
        visited[start]=true;
        int count=1;
        while(!q.empty()){
            int levelSize = q.size();
            for(int k=0;k<levelSize; k++){
                int a=q.front();
                q.pop();
                if(wordList[a]==endWord) return count;
                for(int i=0;i<adj[a].size();i++){
                    if(!visited[adj[a][i]]){
                        visited[adj[a][i]] = true;
                        q.push(adj[a][i]);
                    }
                }
            }
            count++;
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> adj(wordList.size()+1);
        bool check1=false;
        bool check2=false;
        int start;
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList.size();j++){
                if(compare(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                }
                if(wordList[j]==endWord) check1=true;
                if(wordList[j]==beginWord){
                    check2=true;
                    start=j;
                } 
            }
            if(!check1) return 0;
        }
        vector<string> words = wordList;
        if(!check2){
            start=adj.size()-1;
            words.push_back(beginWord);
            for(int i=0;i<wordList.size();i++){
                if(compare(beginWord,wordList[i])){
                    adj[start].push_back(i);
                    adj[i].push_back(start);
                }
            }
        }
        return BFS(words,adj,endWord,start);
    }
};
class TimeMap {
private:
    map <string ,vector<pair<int,string>>> storage;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (storage.find(key) == storage.end()) return "";
        auto& list = storage[key];
        int l=0;
        int r=list.size()-1;
        string res="";
        while(l<=r){
            int mid=l+(r-l)/2;
            if(timestamp >= storage[key][mid].first){
                l=mid+1;
                res = list[mid].second;
                
            } 
            else r=mid-1;
        }
        return res;
    }
};

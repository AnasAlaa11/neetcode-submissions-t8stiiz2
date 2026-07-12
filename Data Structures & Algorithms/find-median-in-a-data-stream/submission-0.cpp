class MedianFinder {
private:
    int BF;
    priority_queue<int> L_pq;
    priority_queue<int,vector<int>,greater<int>> R_pq;
    int root;
    bool start;
public:
    void AVL(){
        BF=R_pq.size()-L_pq.size();
        if(BF==2){
            L_pq.push(root);
            root=R_pq.top();
            R_pq.pop();       
        }
        else if(BF==-2){
            R_pq.push(root);
            root=L_pq.top();
            L_pq.pop();
        }
    }
    MedianFinder() {
        BF=0;
        start=false;
    }
    
    void addNum(int num) {
        if(!start){
            root=num;
            start=true;
        }
        else{
            if(num>=root){
                R_pq.push(num);
                AVL();
            }
            else{
                L_pq.push(num);
                AVL();
            }
        }
    }
    
    double findMedian() {
        BF=R_pq.size()-L_pq.size();
        if(BF==0)
            return root;
        else if(BF==1)
            return ((double)(root+R_pq.top()))/2;
        else
            return ((double)(root+L_pq.top()))/2;
    }
};

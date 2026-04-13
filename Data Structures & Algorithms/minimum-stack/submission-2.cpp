class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        s1.push(val);
        if(mins.empty()||s1.top()<=mins.top()){
            mins.push(s1.top());
        }
    }
    
    void pop() {
        if(!mins.empty()&&s1.top()==mins.top()){
            mins.pop();
        }
        s1.pop();

    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> s1;
    stack <int> mins;
};

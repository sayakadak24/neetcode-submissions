class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        // We push the val and compare the top element with val for min
        if(!st.empty()){
            st.push({val,min(val,st.top().second)});
        }else{
            st.push({val,val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

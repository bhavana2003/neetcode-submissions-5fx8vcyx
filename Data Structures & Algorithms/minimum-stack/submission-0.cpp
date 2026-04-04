class MinStack {
public:
    stack <int> st;
    stack <int> minSt;
    MinStack() {
        minSt.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        minSt.push(min(minSt.top(), val));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

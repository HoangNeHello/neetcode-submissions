class MinStack {
    public:
        MinStack() {}
        
        void push(int val) {
            st.push(val);

            if (!minStack.empty()) {
                minStack.push(min(val, minStack.top())); // Compare and push the minimum one
            } else {
                minStack.push(val);
            }
        }
        
        void pop() {
            st.pop();
            minStack.pop();
        }
        
        int top() {
            return st.top();
        }
        
        int getMin() {
            return minStack.top();
        }

    private:
        stack<int> st;
        stack<int> minStack;
};

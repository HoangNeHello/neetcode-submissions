class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        if (len == 0) {
            return {0};
        }

        stack<int> st;
        vector<int> res(len, 0); // Make a vector the size of temperatures with all values = 0

        for (int i=0; i<len; i++) {
            while (!st.empty() && (temperatures[i] > temperatures[st.top()])) { // st.top() will always < i
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};

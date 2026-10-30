class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int best = 0;

        for (int i=0; i<=n; i++) {
            int h = (i==n) ? 0 : heights[i]; // h is a fake bar when reaches the end. Otherwise, use the elements

            while (!st.empty() && (h < heights[st.top()])) { // Only check if the next one is less than the previous
                int height = heights[st.top()]; // Take the top and pop it
                st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1; // The more we back up, the more width the rectangle has
                best = max(best, height*width);
            }

            st.push(i);
        }

        return best;
    }
};

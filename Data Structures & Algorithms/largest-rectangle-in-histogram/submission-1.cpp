class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> prev;
        int best = 0;

        for (int i=0; i<=heights.size(); i++) {
            int h = (i == n) ? 0 : heights[i]; 

            while (!prev.empty() && (h < heights[prev.top()])) {
                int height = heights[prev.top()];
                prev.pop();
                int width = (prev.empty()) ? i : i - prev.top() - 1; 
                best = max(best, height*width);
            } 
            prev.push(i); // 
        }

        return best;

    }
};

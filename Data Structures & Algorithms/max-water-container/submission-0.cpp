class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int best = 0;
        int temp = best;
        
        while (left < right) {
            int height = min(heights[left] , heights[right]);
            int width = right - left;
            int area = height * width;
            best = area;        

            if (heights[left] < heights[right]) left++;
            else right --;

            if (temp < best) {
                temp = best;
            } else if (temp >= best) {
                best = temp; // Retain the best result;
            }
        }

        return best;
    }
};

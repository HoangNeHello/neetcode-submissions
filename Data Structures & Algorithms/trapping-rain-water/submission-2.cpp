class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxLeft = height[left], maxRight = height[right]; // maxLeft and maxRight act as the barriers
        int count=0;

        while (left<right) {
            if (maxLeft <= maxRight) { // Check if on the left position, can a water be contained?
                left++;
                maxLeft = max(maxLeft, height[left]);
                count += maxLeft - height[left];
            } else { // Same as left but for right
                right--;
                maxRight = max(maxRight, height[right]);
                count += maxRight - height[right];

        }
            }

            return count;
        }

};

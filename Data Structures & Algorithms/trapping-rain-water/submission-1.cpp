class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxLeft = height[left], maxRight = height[right];
        int count=0;

        while (left<right) {
            if (maxLeft <= maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                count += maxLeft - height[left];
            } else {
                right--;
                maxRight = max(maxRight, height[right]);
                count += maxRight - height[right];

        }
            }

            return count;
        }

};

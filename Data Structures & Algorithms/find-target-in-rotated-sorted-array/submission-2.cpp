class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Check if the left side is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is in the left side
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Search left
                } else {
                    left = mid + 1; // Search right
                }
            }

            else { // Otherwise, check right side
                if (nums[right] >= target && target > nums[mid]) {
                    left = mid + 1; // Search left
                } else {
                    right = mid - 1; // Search right
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 2) {
            return min(nums[0], nums[1]);
        } else if (n == 1) {
            return nums[0];
        }

        int left = 0, right = n - 1, min = nums[0];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > min) {
                left = mid + 1;
            } else if (nums[mid] <= min) {
                right = mid - 1;
                min = nums[mid];
            } 
        }
        return min;
    }
};

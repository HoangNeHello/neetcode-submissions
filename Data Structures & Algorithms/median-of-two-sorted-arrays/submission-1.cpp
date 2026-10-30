class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2); // ALWAYS let nums1 < nums2
        int n = nums1.size(), m = nums2.size();
        
        // If you searched the bigger array, some values of i would make j negative or larger than m. -> right = n
        int left = 0, right = n; 
        int half = (n + m + 1) / 2;

        double res;
        while (left <= right) {
            int i = left + (right - left) / 2; // Cut in nums1
            int j = half - i; // Cut in nums2

            // Bounds on where the cut in nums1 is allowed to go.
            int left1 = (i==0) ? INT_MIN : nums1[i-1]; 
            int right1 = (i==n) ? INT_MAX : nums1[i];
            int left2 = (j==0) ? INT_MIN : nums2[j-1];
            int right2 = (j==m) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                if ((n + m) % 2 == 1) res = max(left1, left2); // If total size is odd -> take the middle of 2 lefts
                else res = (max(left1, left2) + min(right1, right2)) / 2.0; // Otherwise calculate
                return res;
            } else if (left1 > right2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return res;
    }
};

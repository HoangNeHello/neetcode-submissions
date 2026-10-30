class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};

        deque<int> dq;
        vector<int> res;

        for (int i=0; i<n; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back(); // Remove the latest index of the element less than the next one.
            }
            dq.push_back(i);

            // Dequeue
            if (dq.front() <= i - k) {
                dq.pop_front(); // Front is old
            } 
            // Record the window
            if (i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};

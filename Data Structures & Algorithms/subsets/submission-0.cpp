class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;

        backtrack(nums, 0, current, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& res) {
        // Save a copy of current into res 
        res.push_back(current);

        // Loop from start to the end of nums
        for (int i=start; i<nums.size(); i++) {
            // Build on the current subset
            current.push_back(nums[i]);

            // Find every subset that starts with this pick
            backtrack(nums, i+1, current, res);

            // Undo the pick so the next i starts fresh
            current.pop_back();
        }
    }
};

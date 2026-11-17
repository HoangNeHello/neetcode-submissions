class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, target, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start, int remaining, vector<int>& path, vector<vector<int>>& res) {
        // Stop #1: <0 -> stop, =0 -> found the combination
        if (remaining < 0) return;
        if (remaining == 0) res.push_back(path);

        for (int i=start; i<nums.size(); i++) {
            // Choose nums[i]
            path.push_back(nums[i]);
            // Go deeper
            backtrack(nums, i, remaining-nums[i], path, res); // Use i because the number passed can also be the combination
            // Go back (unchoose)
            path.pop_back();
        }
    }
};

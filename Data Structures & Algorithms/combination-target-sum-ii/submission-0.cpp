class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, 0, target, path, res);

        return res;
    }

private: 
    void backtrack(vector<int>& nums, int start, int remaining, vector<int>& path, vector<vector<int>>& res) {
        // Stopping: 
        if (remaining < 0) return;
        if (remaining == 0) res.push_back(path);

        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i] == nums[i-1]) continue;
            // Choose
            path.push_back(nums[i]);
            // Go deeper
            backtrack(nums, i+1, remaining-nums[i], path, res); // i+1 because only choose once
            // Unchoose
            path.pop_back();
        }
    }
};

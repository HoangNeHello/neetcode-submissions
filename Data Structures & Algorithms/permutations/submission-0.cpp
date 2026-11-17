class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, res);

        return res;
    }

private: 
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
        // Base case: When the size of permutations = size of nums, push to res and return
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        } 

        for (int i=0; i<nums.size(); i++) {
            // Skip if nums[i] already in the path
            if (used[i] == true) continue;

            // Choose: Add nums[i] and Mark it as used 
            path.push_back(nums[i]);
            used[i] = true;

            // Recurse: 
            backtrack(nums, used, path, res);

            // Go back:
            path.pop_back();
            used[i] = false;
        }
    }
};

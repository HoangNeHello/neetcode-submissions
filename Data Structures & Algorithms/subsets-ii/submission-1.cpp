class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> res;
        backtrack(res, path, 0, nums);

        return res;
    }

private: 
    void backtrack(vector<vector<int>>& res, vector<int>& path, int start, vector<int>& nums) {
        res.push_back(path); // Store the instance

        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i] == nums[i-1]) continue; // Skip duplicates

            path.push_back(nums[i]);
            backtrack(res, path, i+1, nums);
            path.pop_back();
        }
    }
};

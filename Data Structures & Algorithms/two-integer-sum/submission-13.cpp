class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();

        unordered_map<int, int> check;

        for (int i=0; i<length; i++) {
            int complement = target - nums[i]; // Refresh each start with a new complement
            auto answer = check.find(complement); // Using find only ONCE

            if (answer != check.end()) { // Done if it gets the chance to run
                return {answer->second, i};
            }

            check[nums[i]] = i;
        }

        return {};
    }
};
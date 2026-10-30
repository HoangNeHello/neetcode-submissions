class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();

        unordered_map<int, int> check;

        for (int i=0; i<length; i++) {
            check[nums[i]] = i;
        }

        for (int i=0; i<length; i++) {
            int exist = target - nums[i];

            if (check.find(exist) != check.end() && check.find(exist)->second != i) {
                return {i, check.find(exist)->second};
            }
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();

        unordered_map<int, int> check;

        for (int i=0; i<length; i++) {
            check[nums[i]] = i;
        }

        int complement = 0;
        for (int i=0; i<length; i++) {
            int exist = target - nums[i];
            if (check.find(exist) != check.end()) {
                complement = check.find(exist)->second;
                    if (complement != i) {
                    return {i, complement};
                }
            }
        }

        return {};
    }
};
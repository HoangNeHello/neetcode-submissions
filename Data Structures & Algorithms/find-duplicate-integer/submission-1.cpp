class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq_map;

        for (int n:nums) {
            freq_map[n]++;
        }

        for (int i=0; i<nums.size(); i++) {
            if (freq_map[nums[i]] > 1) {
                return nums[i];
            }
        }

        return 0;
    }
};

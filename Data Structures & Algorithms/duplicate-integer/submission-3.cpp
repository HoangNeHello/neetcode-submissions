class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> num;
        for (int i=0; i<nums.size(); i++) {
            num[nums[i]] += 1;

            if (num[nums[i]] > 1) {
                return true;
            } 
        }
        return false;
    }
};
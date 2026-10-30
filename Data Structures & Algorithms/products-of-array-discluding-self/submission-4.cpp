class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int pre = 1;
        for (int i=0; i<nums.size(); i++) {
            result.push_back(pre); // This won't let the nums[i] multiply by itself
            pre *= nums[i];
        }

        int post = 1;
        for (int i=nums.size()-1; i>=0; i--) { // Since pre put the multiplier, now we just need the last piece to multiply
            result[i] *= post;
            post *= nums[i];
        }

        return result;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        ranges::sort(nums);
        int ans = 1;
        int counter = 1;
        for(int r = 1; r < nums.size(); r++)
        {
            if(nums[r - 1] == nums[r]) continue;
            else if(nums[r - 1] + 1 == nums[r])
                ans = max(ans, ++counter);
            else
                counter = 1;
        }
        return ans;
    }
};
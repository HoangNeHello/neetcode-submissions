class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return 1;
    
        sort(nums.begin(), nums.end()); // Sort the number to detect the consecutive

        int count = 1; // count = 1 because when comparing we will ignore the first count
        int prev_best=1, best=1; // To check if best is actually best

        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] + 1 == nums[i+1]) { // If the number is one digit less than its adjacent, the consecutive counts
                count++;
                best = count;
                if (prev_best <= best) {
                    prev_best=best;
                } else {
                    best=prev_best;
                }
            } else if (nums[i] == nums[i+1]) {
                continue;
            } else if (nums[i] != nums[i+1]) { // If the consecutive is broken, add it to best
                count = 1; // Reset to get the new consecutive
            }
        }

        return best;
    }
};

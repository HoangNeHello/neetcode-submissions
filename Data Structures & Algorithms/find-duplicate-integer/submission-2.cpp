class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;

        do { // Use do so the loop runs (idk)
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Reset slow and run again with fast being at the meeting point 
        slow = 0;
        while (slow != fast) { // Walk slowly to the gate (unable to prove)
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

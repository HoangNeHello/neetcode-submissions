class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Treat nums as a linked list: index = node, nums[i] = next
        int slow=0, fast=0;

        do { // Use do since slow == fast at the start, so a while loop would never run
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // They met somewhere in the loop, not necessarily at the gate
        // Reset slow to the start, fast stays at the meeting point
        slow = 0;
        while (slow != fast) { // Both walk 1 step, start->gate and meeting point->gate are the same distance
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast; // slow == fast here, both at the gate = the duplicate
    }
};

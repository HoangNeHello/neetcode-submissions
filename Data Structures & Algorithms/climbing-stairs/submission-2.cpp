class Solution {
public:
    int climbStairs(int n) {
        // Base case: 
        if (n <= 1) return 1;

        // Two variables DP 
        int prev = 1, curr = 1;

        for (int i=2; i<=n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        
        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            for (int num : matrix[mid]) {
                if (num < target) {
                    low = mid + 1;
                } else if (num > target) {
                    high = mid - 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};

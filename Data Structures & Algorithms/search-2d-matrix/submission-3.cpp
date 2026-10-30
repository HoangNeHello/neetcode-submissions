class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // Rows
        int m = matrix[0].size(); // Columns

        int left = 0, right = m * n - 1; // There are m*n elements in the whole matrix

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid/m][mid%m]; // /m is row, %m is column

            if (val < target) {
                left = mid + 1;
            } else if (val > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> LIS(n, vector<int>(m)); // Table, holding the previous increasing value (+1)

        int result = 0;
        for (int row=0; row < n; row++) {
            for (int col=0; col < m; col++) {
                result = max(result, dfs(row, col, LIS, matrix));
            }
        }

        return result;
    }

    int dfs(int row, int col, vector<vector<int>>& LIS, const vector<vector<int>>& matrix) {
        // Out of bounds
        if (row >= matrix.size() || col >= matrix[0].size()) return 0;
        if (row < 0 || col < 0) return 0;

        // Memo check, already solved, move on
        if (LIS[row][col] != 0) return LIS[row][col];
        int best=1;
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // up, left, down, right
        //  Using dir to quick access the directions
        for (auto& d : dir) {
            int nr = row + d[0], nc = col + d[1];

            // Skip the neighbours off the edge of the matrix
            if (nr < 0 || nc < 0 || nr >= matrix.size() || nc >= matrix[0].size()) continue;

            // Only step to a larger value -> increasing path
            if (matrix[nr][nc] > matrix[row][col]) {
                best = max(best, 1 + dfs(nr, nc, LIS, matrix));
            }
        }
        
        LIS[row][col] = best;
        return best;
    }
};

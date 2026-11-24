class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int result = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[row].size(); col++) {
                if (grid[row][col] == '1' && visited[row][col] == false) {
                    result++; // New island found
                    dfs(grid, row, col, visited); // Flood the whole island to scan
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        if (row >= grid.size() || col >= grid[row].size()) return; // Out of bound
        if (row < 0 || col < 0) return; // Out of bound

        // If 0 or 1 true (visited). Skip it 
        if (grid[row][col] == '0' || (grid[row][col] == '1' && visited[row][col] == true)) return; 

        // Mark as visited
        visited[row][col] = true;

        // Recurse 4 directions
        dfs(grid, row, col-1, visited);
        dfs(grid, row-1, col, visited);
        dfs(grid, row, col+1, visited);
        dfs(grid, row+1, col, visited);
    }
};

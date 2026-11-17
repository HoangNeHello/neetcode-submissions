class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string> result;
        backtrack(result, path, 0, 0, n);

        return result;
    }

private: 
    void backtrack(vector<string>& result, string& path, int open, int close, int n) {
        // When to stop or store the result
        if (open == n && close == n) { // Enough brackets
            result.push_back(path);
            return;
        }
        // Choice 1: Add '(' if allowed
        if (open < n) {
            path.push_back('(');
            backtrack(result, path, open+1, close, n);
            path.pop_back();
        } 

        // Choice 2: Add ')' if allowed
        if (close < open) {
            path.push_back(')');
            backtrack(result, path, open, close+1, n);
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;
        backtrack(result, path, 0, s);

        return result;
    }

    void backtrack(vector<vector<string>>& result, vector<string>& path, int start, const string& s) {
        if (start == s.size()) { // Used up all the string 
            result.push_back(path);
            return;
        } 

        for (int i=start; i<s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));

                backtrack(result, path, i+1, s);

                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true; // No mismatch found, every pair matched
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};

        string path;
        vector<string> result;

        // Still include 0 and 1 because we need the index to find the correct letter set.
        vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 0,1,...,9

        backtrack(path, result, letter, digits, 0);

        return result;
    }

    void backtrack(string& path, vector<string>& result, const vector<string> letter, const string& digits, int start) {
        if (start == digits.size()) {
            result.push_back(path);
            return;
        }
        
        string l = letter[digits[start] - '0']; // Get the letter 

        for (int i=0; i<l.size(); i++) {
            // Choose: 
            path += l[i];
            // Go deeper: 
            backtrack(path, result, letter, digits, start+1);
            // Unchoose: 
            path.pop_back();
        }
    }
};

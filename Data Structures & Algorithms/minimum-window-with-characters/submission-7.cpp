class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> freq_map, window_map;
        for (char c : t) {
            freq_map[c]++; // Target counts from t
        }
        int need = freq_map.size(); // Distinct character t needs

        pair<int, int> res = {-1, -1};
        int have = 0, left=0, resLen=INT_MAX;

        for (int right=0; right<s.size(); right++) {
            // Start adding to the right window
            char c = s[right];
            window_map[c] += 1; 

            // Check if it is the required char in substring
            if (freq_map.count(c) && window_map[c] == freq_map[c]) { 
                have++;
            }

            while (have == need) {
                // Save the best possible string
                if (right-left+1 < resLen) {
                    resLen = right-left+1;
                    res = {left, right};
                }
                char out = s[left];
                // Reducing the size of the window
                if (window_map[out] == freq_map[out] && freq_map.count(out)) {
                    have--;
                } 
                window_map[out]--;
                left++;
                
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

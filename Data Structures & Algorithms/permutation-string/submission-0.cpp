class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq_mp;
        for (int i=0; i<s1.size(); i++) {
            // Count the s1 freq
            freq_mp[s1[i]] += 1;
        }

        // Use the window map size s1 to scan s2
        unordered_map<char, int> window_mp;
        for (int i=0; i<s1.size(); i++) {
            window_mp[s2[i]] += 1;
        }

        if (window_mp == freq_mp) return true;

        for (int i=s1.size(); i<s2.size(); i++) {
            window_mp[s2[i]] += 1; // Continue adding

            char char_rm = s2[i-s1.size()]; // Remove the character
            window_mp[char_rm]--;

            if (window_mp[char_rm] == 0) {
                window_mp.erase(char_rm);
            }

            if (window_mp == freq_mp) return true;
        }
        return false;
    }
};

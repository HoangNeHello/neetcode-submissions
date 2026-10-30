class Solution {
public:
    bool isAnagram(string s, string t) {
        int length_s = s.size();
        int length_t = t.size();

        if (length_s != length_t) return false;

        unordered_map<char, int> repeat_s;
        unordered_map<char, int> repeat_t;
        
        for (int i=0; i<length_s; i++) {
            repeat_s[s[i]] += 1;
            repeat_t[t[i]] += 1;
        }

        for (int i=0; i<length_s; i++) {
            if (repeat_s[s[i]] == repeat_t[s[i]]) {
                continue;
            } else return false;
        }

        return true;

    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;

        unordered_set<char> checking;
        int pre=0;
        int max_len = 0; // Because the first element is counted already
        
        for (int post=0; post < len; post++) {
            // Found duplicate, shrink to the left
            while (checking.count(s[post])) {
                checking.erase(s[pre]);
                pre++;
            }

            checking.insert(s[post]);

            max_len = max(max_len, post - pre + 1);
        }

        return max_len;
    }
};

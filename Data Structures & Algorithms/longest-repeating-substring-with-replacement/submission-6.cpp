class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (len == 0) return 0;

        int pre=0;
        int max_size = 0;
        int max_count = 0; // Count the frquency map
        unordered_map<char, int> map_freq;

        for (int post=0; post<len; post++) {
            map_freq[s[post]] += 1;

            max_count = max(max_count, map_freq[s[post]]);

            int chance = post - pre + 1 - max_count; // This will reveal the imposter from the repeated string
            while (chance > k) { // Remove the left char from the map, if we the chance we used exceed k
                map_freq[s[pre]]--; 
                pre++;

                chance = post - pre + 1 - max_count;
            }

            max_size = max(max_size, post-pre+1);
        }

        
        return max_size;
    }
};

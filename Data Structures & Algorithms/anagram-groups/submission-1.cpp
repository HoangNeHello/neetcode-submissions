class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 2) return {{strs}};

        vector<vector<string>> storage;
        unordered_map<string, vector<string>> matching;

        for (int i=0; i<strs.size(); i++) {
            // Sort the string to get them as a key
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());

            auto matched = matching.find(sorted); // Find if the key exists

            if (matched != matching.end()) {
                matched->second.push_back(strs[i]); // Push the value into that key
            } else {
                matching[sorted].push_back(strs[i]); // Grant the newest key as the value.
            }

        }

        for (auto subset : matching) {
            storage.push_back(subset.second);
        }
        

        return storage;
    }
};

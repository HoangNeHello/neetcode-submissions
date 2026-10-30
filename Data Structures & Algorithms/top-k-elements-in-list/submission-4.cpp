class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() < 1) return {};
        if (nums.size() == k) return nums;
        
        unordered_map<int, int> repeated;
        vector<int> storage;

        for (int i=0; i<nums.size(); i++) {
            repeated[nums[i]]++;
        }
        
        vector<pair<int, int>> frequency(repeated.begin(), repeated.end());
        sort(frequency.begin(), frequency.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });

        for (int i=0; i<k; i++) {
            storage.push_back(frequency[i].first);
        }

        return storage;  
    }
};

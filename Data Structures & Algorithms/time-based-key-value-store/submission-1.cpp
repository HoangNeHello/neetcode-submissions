class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if (!storage.count(key)) return ""; // Check if the key was ever set
        auto& v = storage[key]; // Take the value out of the map -> No copy
        int n = v.size();

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                res = v[mid].second;
                left = mid + 1; // Continue searching
            } else {
                // res = v[mid].second; -> TOO NEW. Do nothing
                right = mid - 1; // Continue searching
            } 

        }
        return res;
    }

private:
    unordered_map<string, vector<pair<int, string>>> storage;
};

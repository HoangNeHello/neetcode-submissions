class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        for (int outer=0; outer<points.size(); outer++) {
            int calculation = points[outer][0]*points[outer][0] + points[outer][1]*points[outer][1]; // Because there's only 2 points and comparing with sqrt on it is just the same without it

            minHeap.push(calculation); // Top smallest (a.k.a closest) should be at the top
            calcMap[calculation].push_back(points[outer]); // We now have the index of the pointers
        }

        for (int i=0; i<k; i++) {
            auto it = calcMap.find(minHeap.top()); // 'it' will find the int value
            if (it != calcMap.end()) {
                result.push_back(it->second.back()); // Use back() to get the vector inside of the vector

                // Remove to find the next closest point
                it->second.pop_back();
                minHeap.pop();
            }
        }

        return result;
    }

private: 
    priority_queue<int, vector<int>, greater<int>> minHeap; // Contain the value of the points closest
    unordered_map<int, vector<vector<int>>> calcMap; // Contain the calculation in relation to the points
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        if (len==0) return 0;

        vector<pair<int, int>> cars; // Pairing so that position and speed are sorted together 

        for (int i=0; i<len; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend()); // Sort descendingly because to see if a car is blocked by its ahead

        stack<double> storage;
        for (auto car : cars) {
            double time = (double)(target - car.first) / car.second; // Comparing time in double will make it more accurate
            if (storage.empty() || time > storage.top()) { // If time > top. A new fleet is formed because a car cannot bypass another.
                storage.push(time);
            }
        }

        return storage.size();
    }
};

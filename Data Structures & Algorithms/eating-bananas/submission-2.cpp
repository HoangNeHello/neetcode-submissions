class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int left = 1, right = *max_element(piles.begin(), piles.end()); // Regarding speed

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long long hours = 0;
            for (int banana : piles) {
                hours += (banana + mid - 1) / mid; // Speed = banana / hours -> hours = banana / speed
            }

            if (hours > h) {
                left = mid + 1;
            } else {
                right = mid - 1;;
            }
            
        }
        return left;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> storage;

        for (int i=0; i<nums.size(); i++) {
            if (i!=0) {
                if (nums[i] == nums[i-1]) continue; // SKip duplicate
            }

            int left = i+1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                    continue; // Move on
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    continue; // Move on
                }  
                
                if (nums[i] + nums[left] + nums[right] == 0) { 
                    storage.push_back({nums[i], nums[left], nums[right]}); // FOUND -> Store

                    left++;
                    while (left < right && nums[left] == nums[left-1]) {
                        left++; // Skip duplicate
                        if (nums[left] != nums[left-1]) continue;
                    }

                    right--; 
                    while (left < right && nums[right] == nums[right+1]){
                        right--;
                        if (nums[right] != nums[right+1]) continue; // Skip duplicate
                    }

                    continue; // Move on
                } 
                
                
            }

        }

        return storage;    
    }
};

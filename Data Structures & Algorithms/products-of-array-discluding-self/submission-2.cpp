class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() < 2) return nums;

        vector<int> output;
        vector<int> prefix;
        vector<int> postfix;

        int left_prod = 1;
        for (int i=0; i<nums.size(); i++) {
            left_prod = left_prod * nums[i];
            prefix.push_back(left_prod);
        }

        int right_prod = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            right_prod = right_prod * nums[i];
            postfix.push_back(right_prod);
        }
        reverse(postfix.begin(), postfix.end());

        for (int i=0; i<nums.size(); i++) {
            int j=i+1;
            if (i==0) {
                output.push_back(postfix[j]);
            } else if (j==nums.size()) {
                output.push_back(prefix[i-1] * 1);
            } else {
                output.push_back(prefix[i-1] * postfix[j]);
            }
        }
        

        return output;
    }
};

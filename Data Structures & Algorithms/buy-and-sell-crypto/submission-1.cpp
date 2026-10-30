class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        int buy=0, sell=1; // Indeces
        int res = 0;
        while (buy < len && sell < len) {
            if (prices[buy] < prices[sell]) {
                res = max(res, prices[sell] - prices[buy]); // Maximizing profit
                sell++;
            } 
            else {
                buy = sell; // Because prices[sell] < prices[buy], so it can be maximized if the day we sell is the day we buy.
                sell++;
            }
        }

        return res;
    }
};

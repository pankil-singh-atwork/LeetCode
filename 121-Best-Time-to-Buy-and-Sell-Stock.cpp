class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minimum = INT_MAX;
        // run a loop
        for (int i=0;i<prices.size();i++) {
            minimum = min(prices[i] , minimum);
            // finding the profit
            int profit = prices[i] - minimum;
            maxProfit = max(profit , maxProfit);
        }
        return maxProfit;
    }
};
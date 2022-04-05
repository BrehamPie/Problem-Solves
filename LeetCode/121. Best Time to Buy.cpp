/*
    for each day we see the profit we will make if we brought it
    with the lowest price so far.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lowestPrice = prices[0];
        for (int x : prices) {
            lowestPrice = min(lowestPrice, x);
            profit = max(profit, x - lowestPrice);
        }
        return profit;
    }
};
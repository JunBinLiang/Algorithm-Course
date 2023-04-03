class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = prices[0];
        //Sell at day i with prices[i]
        //We need to buy at preices[0 : i - 1]
        //The maximum we can earn is prices[i] = min(prices[0 : i - 1])
        for(int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - buy);
            buy = min(buy, prices[i]);
        } 
        return res;
    }
};

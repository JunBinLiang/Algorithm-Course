class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = prices[0];
        //If sell at day i
        for(int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - buy);
            buy = min(buy, prices[i]);
        } 
        return res;
    }
};

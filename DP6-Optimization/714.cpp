class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n);
        
        //dp[i] : maximum you can earn at day i
        //for day j < i, buy with prices[j] and sell with (dp[j - 1] + prices[i] - prices[j] - fee)
        //dp[i] = max(dp[j - 1] + prices[i] - prices[j] - fee)
        
        //((dp[j - 1] - prices[j] - fee)  + prices[i])
        
        //fixed i
        int mx = - prices[0] - fee;
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], prices[i] + mx);
            mx = max(mx, dp[i - 1] - prices[i] - fee);
        }
        return dp[n - 1];
    }
};


/* brute force

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n);
        
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            for(int j = i - 1; j >= 0; j--) {
                if(j - 1 >= 0)
                    dp[i] = max(dp[i], prices[i] + dp[j - 1] - prices[j] - fee);
                else dp[i] = max(dp[i], prices[i] - prices[j] - fee);
            }
        }
        
        return dp[n - 1];
    }
};
*/

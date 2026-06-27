class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1<<15);
        dp[0]=0;
        for(int coin: coins){
            for(int j=coin;j<=amount;j++){
                dp[j]=min(dp[j],1+dp[j-coin]);
            }
        }
        return dp[amount]==1<<15?-1:dp[amount];
    }
};
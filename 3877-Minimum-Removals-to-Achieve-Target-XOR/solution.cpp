class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int x : nums) {
            auto new_dp = dp;
            for (auto &[xr, cnt] : dp) {
                int new_xr = xr ^ x;
                new_dp[new_xr] = max(new_dp[new_xr], cnt + 1);
            }
            dp = new_dp;
        }

        if (dp.count(target)) {
            return n - dp[target];
        }
        return -1;
    }
};
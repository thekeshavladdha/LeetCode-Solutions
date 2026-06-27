class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0, diff, res = 0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0){
                zero++;
            }
            else one++;
            diff = zero - one;
            
            
            if (!mp.count(diff))
                mp[diff] = i;
            res = max(res, i - mp[diff]);
        }
        return res;
    }
};
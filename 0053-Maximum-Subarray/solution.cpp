class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            mx=max(mx+nums[i],nums[i]);
            ans=max(mx,ans);
        }
        return ans;
    }
};
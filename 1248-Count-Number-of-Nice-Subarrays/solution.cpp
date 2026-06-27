class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int mp[n+1]={0};
        int sum=0,res=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]&1;
            if(sum>=k)
                res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};
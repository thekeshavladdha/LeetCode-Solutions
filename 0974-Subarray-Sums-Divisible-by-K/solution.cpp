class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,res=0,rem;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res+=mp[sum%k<0?sum%k+k:sum%k]++;
        }
        return res;
        
    }
};
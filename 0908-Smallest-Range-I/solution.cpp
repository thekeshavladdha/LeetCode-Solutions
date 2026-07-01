class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        nums[0]+=k;
        nums[n]-=k;
        return nums[n]>nums[0]?nums[n]-nums[0]:0;
    }
};
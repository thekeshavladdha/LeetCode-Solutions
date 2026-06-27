class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0]==0?1:0;
        for(int i=1;i<nums.size();i++){
            nums[0]+=nums[i];
        }
        return (nums.size()*(nums.size()+1)/2)-nums[0];
    }
};
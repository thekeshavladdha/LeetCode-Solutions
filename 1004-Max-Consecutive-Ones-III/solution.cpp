class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,count=0,res=0,zerocount;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0) zerocount++;
            count++;
            while(zerocount>k){
                if(nums[left]==0) zerocount--;
                left++;
                count--;
            }
            res=max(res,count);
        }
        return res;

    }
};
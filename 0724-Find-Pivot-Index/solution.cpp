class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0,sum=0;
        for(auto &x: nums){
            sum+=x;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0) left+=nums[i-1];
            if(i<=nums.size()-1) sum=sum-nums[i];
            if(left==sum){
                return i;
            }
        }
        return -1;
    }
};
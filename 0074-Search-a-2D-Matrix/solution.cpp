class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int low=0,high=nums.size()*nums[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/nums[0].size(),col=mid%nums[0].size();
            if(nums[row][col]==target) return true;
            else if(nums[row][col]<target) low=mid+1;
            else high=mid-1;
        }   
        return false;
    }
};
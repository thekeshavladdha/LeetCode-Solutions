class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int i=0,j=nums[0].size()-1;
        while(j>=0 && i<nums.size()){
            if(nums[i][j]==target) return true;
            else if(nums[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
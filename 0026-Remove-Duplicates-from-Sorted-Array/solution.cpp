class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1,k=0;
        while(i<=j && j<nums.size()){
            if(nums[j]==nums[j-1]) j++;
            else{
                nums[i+1]=nums[j];
                i++;
                j++;
                k++;
                
            }

        }
        return k+1;
    }
};
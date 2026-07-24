class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        if(nums.size()==1) return nums[0]<x?1:0;
        if(x<nums[0]) return 0;
        long long left=0,right=nums.size()-1;
        long long ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==x) return mid;
            else if(nums[mid]>x){
                
                right=mid-1;
            }
            else{
                ans=mid+1;
                left=mid+1;
            }
        }
        return ans;
    }
};
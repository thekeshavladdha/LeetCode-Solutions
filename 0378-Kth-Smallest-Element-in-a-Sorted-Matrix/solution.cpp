class Solution {
private:
    int checkCount(vector<vector<int>>& nums, int mid,int i,int j){
        int res=0;
        while(i>=0 && j<nums[0].size()){
            if(nums[i][j]>mid){
                i--;
            }
            else{
                res+=i+1;
                j++;
            }
            
        }
        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& nums, int k) {
        int low=nums[0][0],high=nums[nums.size()-1][nums[0].size()-1];
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(checkCount(nums,mid,nums.size()-1,0)>=k){ 
                res=mid;
                high= mid-1;
            }
            else if(checkCount(nums,mid,nums.size()-1,0)<k) low=mid+1;
            
        }
        return res;

    }
};
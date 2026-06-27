class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int minprod=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevmax=maxprod;
            int prevmin=minprod;
            maxprod=max({prevmax*nums[i],prevmin*nums[i],nums[i]});
            minprod=min({prevmax*nums[i],prevmin*nums[i],nums[i]});
            res=max(res,max(maxprod,minprod));
        }
        return res;
    }
};
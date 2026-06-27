class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k) return 0;
        double avgSum=0;
        double avg;
        for(int i=0;i<k;i++){
            avgSum+=nums[i];
        }
        avg=avgSum/k;
        double res=avg;
        for(int i=k;i<nums.size();i++){
            avgSum+=nums[i]-nums[i-k];
            avg=avgSum/k;
            res=max(res,avg);
        }
        return res;
    }
};
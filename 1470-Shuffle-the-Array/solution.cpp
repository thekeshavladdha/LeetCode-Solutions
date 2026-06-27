class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int j=0,k=0;
        vector<int> ans(2*n);
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                ans[i]=nums[j];
                j++;
            }
            else{ 
                ans[i]=nums[n+k];
                k++;
            }
        }
        return ans;
    }
};
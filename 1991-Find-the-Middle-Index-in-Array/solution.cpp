class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int prefix[2*n];
        prefix[0]=(nums[0]);
        prefix[2*n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=(prefix[i-1]+nums[i]);
        }
        for(int i=2*n-2;i>=n;i--){
            prefix[i]=nums[i-n]+prefix[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(prefix[i]==prefix[n+i]) return i;
        }
        return -1;
    }   
};
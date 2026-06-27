class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int sum=0,dup,tot;
        vector<int> arr(n);
        for(int x: nums){
            if(arr[x-1]!=0){ dup=x;}
            arr[x-1]++;
            sum+=x;

        }
        tot=n*(n+1)/2;
        return {dup,(tot-sum+dup)};

        

    }
};
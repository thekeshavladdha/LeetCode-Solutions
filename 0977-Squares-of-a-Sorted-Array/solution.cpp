class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        vector<int> temp;
        for(int num:nums){
            temp.push_back(num);
            if(num<0) j++;
        }
        int k=0,i=j-1;
        while(i>=0 && j<n){
            if(temp[i]*temp[i]>=temp[j]*temp[j]){
                nums[k]=temp[j]*temp[j];
                k++;
                j++;
            }
            else{
                nums[k]=temp[i]*temp[i];
                k++;
                i--;
            }
        }
        while(i>=0){
            nums[k]=temp[i]*temp[i];
            i--;
            k++;
        }
        while(j<n){
            nums[k]=temp[j]*temp[j];
            j++;
            k++;
        }
        return nums;
    }
};
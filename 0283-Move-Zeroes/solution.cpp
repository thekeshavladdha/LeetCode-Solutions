class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0,j=0;
        if(arr.size()==1) return;
        while(i<arr.size()){
            if(arr[i]==0){
                i++;
            }
            else{
                arr[i]=arr[i]^arr[j];
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
                i++;
                j++;
            }
        }
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        long long ans=-1;
        long long left=0, right=x/2;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid>x){
                
                right=mid-1;
            }
            else{
                ans=mid;
                left=mid+1;
            }
        }
        return ans;
    }
};
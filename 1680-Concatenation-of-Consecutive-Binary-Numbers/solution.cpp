class Solution {
public:
    int concatenatedBinary(int n) {
        long long result=0,digits=0,m=1e9+7;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0) digits++;
            result=((result<<digits)|i)%m;
        }
        return result;
    }
};
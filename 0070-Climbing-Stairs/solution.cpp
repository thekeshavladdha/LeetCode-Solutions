class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        int sum=b;
        for(int i=0;i<=n-2;i++){
            sum=a+b;
            b=a;
            a=sum;
        }
        return sum;
    }
};

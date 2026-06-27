class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x,rem;
        long rev=0;
        if(x<0) return false;
        while(x){
            rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        if(temp==rev) return true;

        return false;
    }
};
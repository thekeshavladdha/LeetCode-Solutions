class Solution {
public:
    int digit(int n){
        int result=0;
        while(n){
            result+=(n%10)*(n%10);
            n/=10;
        }
        return result;
    }
    bool isHappy(int n) {
        int slow=digit(n);
        int fast = digit(n);
        fast= digit(fast);
        while(fast!=1){
            slow=digit(slow);
            fast = digit(fast);
            fast = digit(fast);
            if(fast== slow) return false;

        }
        return true;
    }
};
class Solution {
public:
    int hammingWeight(int n) {
        
        while(n>0){
            n=n&n-1;
            static int count;
            count++;
        }
        int(return count);
        
    }
};
class Solution {
public:
    int bitwiseComplement(int n) {
        int temp=n,andd=0;
        if(n==0) return 1;
        while(temp){
            temp=temp>>1;
            andd=(andd<<1|1);
        }
        n=~n&andd;
        return n;
    }
};
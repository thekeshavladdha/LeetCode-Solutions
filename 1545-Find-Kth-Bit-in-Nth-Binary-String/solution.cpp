class Solution {
public:
    char findKthBit(int n, int k) {
        int len=(1<<n)-1;
        return recur(len,k);
    }
    char recur(int len,int k){
        if(len==1) return '0';
        int half=len/2;
        if(k==(half+1)){
            return '1';
        }
        else if(k<(half+1)){
            return recur(half,k);
        }
        else{
            return (recur(half,len-k+1)=='0')?'1':'0';
            
        }
        
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int minsum=a[0];
        int maxsum=a[0];
        int res=a[0]; 
        if(a.size()==1) return abs(a[0]);
        for(int i=1;i<a.size();i++){
            minsum=min(minsum+a[i],a[i]);
            maxsum=max(maxsum+a[i],a[i]);

            res=max(res,max(abs(minsum),maxsum));
        }
        return res;
    }
};
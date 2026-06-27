class Solution {
public:
    vector<int> grayCode(int n) {
        long long m=1<<n;
        vector<int> res;
        int ans=0;
        for(int i=0;i<m;i++){
            ans=i^(i>>1);
            res.push_back(ans);
        }
        return res;
    }
};
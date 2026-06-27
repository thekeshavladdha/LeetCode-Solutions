class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0,idx=0;
        const int constnt=1e9+7;
        for(auto& query:queries){
            for(int idx=query[0];idx<=query[1];idx+=query[2]){
                nums[idx]=(1LL*nums[idx]*query[3])%constnt;
            } 
        }
        for(auto& num:nums){
            res=res^num;
        }
        return res;
    }
};
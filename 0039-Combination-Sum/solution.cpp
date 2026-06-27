class Solution {
public:
    void comb(vector<int>& candidates, int target,vector<int>& temp,vector<vector<int>>& result,int n){
        if(n==0 || target<0) return;
        if(target==0){
            result.push_back(temp);
            return;
        }
        temp.push_back(candidates[n-1]);
        comb(candidates,target-candidates[n-1],temp,result,n);
        temp.pop_back();
        comb(candidates,target,temp,result,n-1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        comb(candidates,target,temp,result,candidates.size());
        return result;
    }
};
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res,vector<int>& temp,int idx){
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,res,temp,i+1);
            temp.pop_back();
        }
        res.push_back(temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,res,temp,0);
        return res;
    }
};
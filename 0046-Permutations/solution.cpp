class Solution {
public:
    void perm(vector<int>& nums, vector<vector<int>>& res,vector<int>& temp,int n,int idx,vector<bool>& used){
        if(idx==n){
            res.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i]) continue;
            used[i]=true;
            temp.push_back(nums[i]);
            
            perm(nums,res,temp,n,idx+1,used);
            
            used[i]=false;
            temp.pop_back();
        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        perm(nums,res,temp,nums.size(),0,used);
        return res;
    }
};
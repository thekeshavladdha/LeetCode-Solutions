class Solution {
public:
    void perm(vector<int>& nums, vector<int>& temp, unordered_Set<int>& used,
              vector<vector<int>>& res,vector<bool> usedd) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            
            return;
        }
        for(int i=0;i<nums.size();i++){
            
            if(usedd[i]) continue;
            temp.push_back(nums[i]);
            usedd[i]=true;
            perm(nums,temp,used,res,usedd);
            temp.pop_back();
            usedd[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> used;
        
        perm(nums,temp,used,res,usedd);
        return res;
    }
};
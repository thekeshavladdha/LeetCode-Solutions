class Solution {
public:
    
    void func(vector<int>& nums,int ind,vector<int>& temp,vector<vector<int>>& result){
        if(nums.size()==ind){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(nums,ind+1,temp,result);
        temp.pop_back();
        func(nums,ind+1,temp,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int> temp;
        vector<vector<int>> result;
        func(nums,0,temp,result);
        return result;
    }
};
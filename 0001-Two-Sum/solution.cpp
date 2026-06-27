class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int idx1, idx2;
        for (int i = 0; i < nums.size(); i++) {
            
            if (mp.count(nums[i])) {
                idx1 = i;
                idx2 = mp[nums[i]];
                break;
            }
            mp[target - nums[i]]=i;
        }
        return {idx1, idx2};
    }
};

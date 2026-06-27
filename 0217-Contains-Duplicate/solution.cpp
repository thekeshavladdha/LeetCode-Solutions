class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int x: nums){
            if(f.count(x)) return true;
            f[x]++;
        }
        
        return false;
    }
};
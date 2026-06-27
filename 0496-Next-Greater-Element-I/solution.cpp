class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> num;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!num.empty() && num.top()<=nums2[i]){
                num.pop();
            }
            mp[nums2[i]]=num.empty()?-1:num.top();
            num.push(nums2[i]);
            
        }
        vector<int> res;
        for(auto &x:nums1){
            res.push_back(mp[x]);
        }
        return res;
    }
};
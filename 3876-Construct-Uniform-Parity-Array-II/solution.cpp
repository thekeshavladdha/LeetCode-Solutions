class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int small=INT_MAX;
        int count=0;
        for(int x: nums1){
            small=min(small,x);
            if(x%2==0) count++;
        }
        if(count==nums1.size()) return true;
        return (small%2==1);
    }
};
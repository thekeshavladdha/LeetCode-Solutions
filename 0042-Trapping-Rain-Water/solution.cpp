class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int min=0;
        int i=0,j=height.size()-1;
        while(i<j){
            if(height[i]<=height[j]){
                min=max(height[i],min);
                i++;
                ans+=min-height[i]>0?min-height[i]:0;
            }
            else{
                min=max(height[j],min);
                j--;
                ans+=min-height[j]>0?min-height[j]:0;
            }
        }
        return ans;
    }
};
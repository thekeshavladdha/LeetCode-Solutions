class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size(),area=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                int idx=st.top();
                st.pop();
                area=max(area,heights[idx]*(st.empty()?i:i-st.top()-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx=st.top();
            st.pop();
            area=max(area,heights[idx]*(st.empty()?n:n-st.top()-1));
        }
        return area;
    }
};
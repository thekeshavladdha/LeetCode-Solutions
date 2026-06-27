class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        st.push(n-1);
        res[n-1]=0;
        for(int i=n-2;i>=0;i--){
            
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }

            if(!st.empty()){
                res[i]=st.top()-i;
                
            }
            st.push(i);
        }
        return res;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size()==1) return s;
        stack<char> st;
        int i=s.size()-1;
        string ans="";
        for(i;i>=0;i--){
            if(!st.empty() && s[i]==st.top()){
                st.pop();
            }
            else
                st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size();
        st.push({s[n - 1], 1});

        for (int i = n - 2; i >= 0; i--) {
            if (!st.empty() && s[i] == st.top().first) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            }
            else
                st.push({s[i], 1});
        }
        string ans;
        while (!st.empty()) {
            while (st.top().second != 0) {
                ans.push_back(st.top().first);
                st.top().second--;
            }
            st.pop();
        }

        return ans;
    }
};
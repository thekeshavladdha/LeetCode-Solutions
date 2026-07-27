class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> st;
        int l = 0, ans = 0;
        
        for (int r = 0; r < fruits.size(); r++) {
            st[fruits[r]]++;
            
            while (st.size() > 2) {
                st[fruits[l]]--;
                if (st[fruits[l]] == 0) {
                    st.erase(fruits[l]);
                }
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
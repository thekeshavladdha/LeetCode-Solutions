class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(256,0), have(256,0);

        for(char c : t)
            need[c]++;

        int required = 0;
        for(int i=0;i<256;i++)
            if(need[i] > 0)
                required++;

        int formed = 0;
        int l = 0, r = 0;
        int start = 0, minLen = INT_MAX;

        while(r < s.size()) {
            char c = s[r];
            have[c]++;

            if(have[c] == need[c] && need[c] > 0)
                formed++;

            while(l <= r && formed == required) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                have[s[l]]--;
                if(have[s[l]] < need[s[l]] && need[s[l]] > 0)
                    formed--;

                l++;
            }

            r++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
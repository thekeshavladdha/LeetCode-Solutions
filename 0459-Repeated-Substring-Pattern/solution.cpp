class Solution {
public:
    vector<int> LPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0) {
                    len = lps[len - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> lps = LPS(s);

        int n = s.size();
        int maxPS = lps[n - 1];

        return maxPS > 0 && n % (n - maxPS) == 0;
    }
};
class Solution {
public:
    bool isZero(int freq[]) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;

        int freq[26] = {0};

        for(int i = 0; i < n; i++) {
            freq[s2[i] - 'a']++;
            freq[s1[i] - 'a']--;
        }

        if(isZero(freq)) return true;

        int j = 0;

        for(int i = n; i < m; i++) {
            freq[s2[j] - 'a']--;  // character leaving window
            freq[s2[i] - 'a']++;  // character entering window

            if(isZero(freq)) return true;

            j++;
        }

        return false;
    }
};
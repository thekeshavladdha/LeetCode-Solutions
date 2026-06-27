class Solution {
public:
    bool isZero(int freq[]) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        
        int n=s.size(),m=p.size();
        if(n<m) return {};
        int freq[26]={0};
        vector<int> res;
        for(int i=0;i<m;i++){
            freq[p[i]-'a']++;
            freq[s[i]-'a']--;
        }
        if(isZero(freq)) res.push_back(0);
        int j=0;
        for(int i=m;i<n;i++){
            freq[s[j]-'a']++;
            freq[s[i]-'a']--;
            j++;
            if(isZero(freq)) res.push_back(j);
        }
        return res;
    }
};
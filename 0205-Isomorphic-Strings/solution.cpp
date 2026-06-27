class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> iso;
        for (int i = 0; i < s.size(); i++) {
            int count=0;
            if(iso.count(s[i]) && iso[s[i]] != t[i])
                return false;
            for(auto p: iso){
                if(p.second==t[i]) count=1;
            }
            if(count==1) continue;
            iso[s[i]] = t[i];
        }
        for (int i = 0; i < s.size(); i++) {
            if (t[i] != iso[s[i]])
                return false;
        }
        return true;
    }
};
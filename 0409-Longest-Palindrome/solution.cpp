class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1) return 1;
        unordered_map<char,int> mp;
        for(auto &c: s){
            mp[c]++;
        }
        int count=0;
        for(auto &x:mp){
            if(x.second%2!=0) count++;
        }
        if(count==0) return s.size();
        return s.size()-(count-1);
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        reverse(s.begin(),s.end());
        while(i<s.size() && s[i]== ' ') s.erase(i,1);
        while(i<s.size()){
            int j=i;
            while(j<s.size() && s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            while(j+1<s.size() &&s[j+1]==' ') s.erase(j+1,1);
            i=j+1;
        }
        if(!s.empty() && s.back()==' ') s.pop_back();
        return s;
    }
};
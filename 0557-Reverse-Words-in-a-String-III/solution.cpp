class Solution {
public:
    string reverseWords(string s) {
        int i =0,j=0;
        while(j<s.size()){
            if(s[j]==' '){
                reverse(s.begin()+i,s.end()-(s.size()-j));
                i=j+1;
            }
            j++;
        }
        reverse(s.begin()+i,s.end()-(s.size()-j));
        return s;
    }
};
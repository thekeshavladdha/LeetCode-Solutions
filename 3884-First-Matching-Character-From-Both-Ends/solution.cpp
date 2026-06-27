class Solution {
public:
    int firstMatchingIndex(string s) {
        int i=0,j=s.size(),ans=-1;
        while(i<j){
            if(s[i]==s[j-i-1]){
                ans=i;
                break;
            }
            i++;
        }
        return ans;;
    }
};
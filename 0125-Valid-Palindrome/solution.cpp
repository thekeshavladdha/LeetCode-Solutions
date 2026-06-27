class Solution {
public:
    bool isPalindrome(string s) {
        string result="";
        if(s.size()<=1) return true;
        for(auto str:s){
            if(isalnum(str)){
                result+=tolower(str);
            }
        }
        int i=0,j=result.size()-1;
        while(i<j){
            if(result[i]==result[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

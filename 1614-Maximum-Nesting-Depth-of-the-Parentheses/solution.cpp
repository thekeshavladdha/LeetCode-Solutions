class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int result=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('){
                open++;
            }
            
            if(s[i]==')'){
                result=max(result,open);
                open--;
            }
        }
        return result;
    }
};
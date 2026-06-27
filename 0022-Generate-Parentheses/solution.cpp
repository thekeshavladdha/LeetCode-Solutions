class Solution {
public:
    void backtrack(int n, vector<string>& result, int open, int close,
                   string& temp) {
        
        if(close>open) return;
        if (open == n && close == n) {
            result.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            backtrack(n, result, open+1, close, temp);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            backtrack(n, result, open, close+1, temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int open = 0, close = 0;
        string temp;
        backtrack(n, result, open, close, temp);
        return result;
    }
};
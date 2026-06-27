class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='[') par.push(c);
            else if(par.empty()) return false;
            else if(c==')' && par.top()=='(') par.pop();
            else if(c=='}' && par.top()=='{') par.pop();
            else if(c==']' && par.top()=='[') par.pop();
            else return false;
        }
        if(par.empty()) return true;
        return false;
    }
};
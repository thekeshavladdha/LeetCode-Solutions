class Solution {
public:
string DFS(string &s, int &i){
       string miniDecode="", curr="";
       int num=0;
       
       while(i<s.size()){

        if(isdigit(s[i])){
            num=num*10+(s[i]-'0');
            i++;
        }
        else if(s[i]=='['){
            i++;
            miniDecode=DFS(s,i);
            while(num--){
                curr+=miniDecode;
            }
            num=0;
        }
        else if(s[i]==']'){
            i++;
            return curr;
        }
        else{
            curr+=s[i];
            i++;
        }

       } 
       return curr;
    }
    string decodeString(string s) {
        int i=0;
        return DFS(s,i);
    }
};
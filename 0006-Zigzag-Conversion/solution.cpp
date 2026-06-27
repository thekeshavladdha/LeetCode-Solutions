class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows);
        int currROW=0;
        bool down=false;
        if(numRows==1) return s;
        for(int i=0;i<s.size();i++){
            result[currROW].push_back(s[i]);
            if(currROW==0||currROW==numRows-1){
                down=!down;
            }
            if(down){
                currROW++;
            }
            else{
                currROW--;
            }
        }
        string ans;
        for(string res: result){
            ans+=res;
        }
        return ans;
    }
};
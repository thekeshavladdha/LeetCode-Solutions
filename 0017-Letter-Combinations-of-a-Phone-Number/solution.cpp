class Solution {
public:
    void rec(string digits, unordered_map<char, string> phone,int index,vector<string>& result,string temp) {
        if(index==digits.size()){
            result.push_back(temp);
            return;
        }
        for(auto y:phone[digits[index]]){
            temp.push_back(y);
            rec(digits, phone,index+1,result,temp);
            temp.pop_back();

        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                            {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> result;
        string temp="";
        rec(digits, phone,0,result,temp);
        return result;
    }
};

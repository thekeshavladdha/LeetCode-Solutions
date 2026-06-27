class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> freq;
        for(auto str:strs){
            string word(26,'0');
            for(auto ch:str){
                word[ch-'a']++;
            }
            
            
            freq[word].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& [y,x]:freq){
            result.push_back(x);
        }
        return result;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& height) {
       unordered_map<int,string> map;
       for(int i=0;i<names.size();i++){
        map[height[i]]=names[i];
       } 
       sort(height.rbegin(),height.rend());
       for(int i=0;i<names.size();i++){
        names[i]=map[height[i]];
       }
       return names;
    }
};
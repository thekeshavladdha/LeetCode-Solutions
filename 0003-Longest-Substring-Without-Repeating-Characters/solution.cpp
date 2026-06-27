class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0,high;
        int len=0;
        char freq[256]={0};
        for(high=0;high<s.size();high++){
            while(freq[s[high]]){
                freq[s[low]]--;;
                low++;
            }
            freq[s[high]]++;
            
            len=max(high-low+1,len);
            
            
        }
        
        return len;
    }
};
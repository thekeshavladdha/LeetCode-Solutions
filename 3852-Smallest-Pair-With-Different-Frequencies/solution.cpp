class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> freq;

        for(int x : nums) freq[x]++;

        int firstVal = -1;
        int firstFreq = -1;

        for(auto &p : freq) {
            if(firstVal == -1) {
                firstVal = p.first;
                firstFreq = p.second;
            } else {
                if(p.second != firstFreq) {
                    return {firstVal, p.first};
                }
            }
        }

        return {-1,-1};
    }
};
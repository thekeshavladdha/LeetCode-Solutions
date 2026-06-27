class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> dur(256, 0);

        // first key
        dur[keysPressed[0]] = releaseTimes[0];

        // compute durations
        for(int i = 1; i < keysPressed.size(); i++){
            int d = releaseTimes[i] - releaseTimes[i-1];
            dur[keysPressed[i]] = max(dur[keysPressed[i]], d);
        }

        int maxi = -1;
        int index = 0;

        for(int i = 0; i < 256; i++){
            if(dur[i] >= maxi){
                maxi = dur[i];
                index = i;
            }
        }

        return char(index);
    }
};
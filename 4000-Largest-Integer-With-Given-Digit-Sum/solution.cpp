#include <algorithm>

class Solution {
public:
    int largestInteger(int n, int s) {
        
        if (s > 9 * n) {
            return -1;
        }
        
        int result = 0;
        
        
        for (int i = 0; i < n; ++i) {
            
            int digit = std::min(s, 9);
            result = result * 10 + digit;
            s -= digit;
        }
        
        return result;
    }
};
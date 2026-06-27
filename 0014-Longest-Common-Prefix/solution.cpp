class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If there is only one string,
        // that string itself is the longest common prefix.
        if(strs.size()==1) return strs[0];

        int smallestIdx = 0, idx = 0;
        int size, MinSize = INT_MAX;

        // Find the smallest string in the vector.
        // We use the smallest string as reference because
        // the common prefix cannot be longer than it.
        for(string str : strs){
            size = str.size();

            if(size < MinSize){
                smallestIdx = idx;
                MinSize = size;
            }

            idx++;
        }

        // Store the smallest string as reference.
        string reference = strs[smallestIdx];

        idx = 0;
        int count = 0;

        // Stores the minimum matching prefix length found so far.
        int result = INT_MAX;

        // Compare every string with the reference string.
        for(string str : strs){

            // Skip comparing the reference string with itself.
            if(idx == smallestIdx){
                idx++;
                continue;
            }

            // Compare characters one by one.
            for(int i = 0; i < MinSize; i++){

                // Stop when characters stop matching.
                if(str[i] != reference[i]) break;

                // Count matching characters.
                count++;
            }

            idx++;

            // Store the minimum common prefix length.
            result = min(result, count);

            // Reset count for next string comparison.
            count = 0;
        }

        // Edge case:
        // If result was never updated, return empty string.
        if(result == INT_MAX) return "";

        string ans = "";

        // Build the answer using the common prefix length.
        for(int i = 0; i < result; i++){
            ans += reference[i];
        }

        return ans;
    }
};
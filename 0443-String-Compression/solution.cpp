class Solution {
public:
    int compress(vector<char>& chars) {
        int updt = 0;
        int j = 0;
        int count = 0;
        while (j < chars.size()) {
            char curr = chars[j];
            while (j < chars.size() && chars[j] == curr) {
                count++;
                j++;
            }

            chars[updt++] = curr;
            if (count > 1) {
                string str=to_string(count);
                for (auto ch : str) {
                    chars[updt++] = ch;
                }
            }
            count = 0;
        }
        return updt;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        vector<vector<int>> bucket(n + 1);
        for (auto& [val, cnt] : freq) {
            bucket[cnt].push_back(val);
        }

        vector<int> result;
        for (int i = n; i >= 1 && result.size() < k; i--) {
            for (int val : bucket[i]) {
                result.push_back(val);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
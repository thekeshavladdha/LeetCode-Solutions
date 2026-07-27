class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return 0;

        unordered_map<int, int> countMap;
        long long currentSum = 0, maxSum = 0;

        // 1. Initialize the first window of size k
        for (int i = 0; i < k; i++) {
            countMap[nums[i]]++;
            currentSum += nums[i];
        }

        // Check the first window
        if (countMap.size() == k) {
            maxSum = currentSum;
        }

        // 2. Slide the window across the rest of the array
        for (int i = k; i < n; i++) {
            int incoming = nums[i];
            int outgoing = nums[i - k];

            // Add incoming element
            countMap[incoming]++;
            currentSum += incoming;

            // Remove outgoing element
            countMap[outgoing]--;
            if (countMap[outgoing] == 0) {
                countMap.erase(outgoing);
            }
            currentSum -= outgoing;

            // If all elements in the current window are distinct
            if (countMap.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};
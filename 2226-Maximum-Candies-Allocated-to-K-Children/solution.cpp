class Solution {
public:
    bool communist(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        int batch = 0;
        for (int i = 0; i < candies.size(); i++) {
            batch = candies[i];
            count += batch / mid;
            if (count >= k)
                return true;
        }

        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long low = 1, high=-1;
        int res = -1;
        long long sum = 0;
        for (auto x : candies) {
            sum += x;
        }
        
        if (sum < k)
            return 0;

        high=sum/k;
        while (low <= high) {
            long long mid = (low + (high - low) / 2);
            if (communist(candies, k, mid)) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }
};
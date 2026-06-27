#pragma GCC optimize("Ofast,unroll-loops") 
#pragma GCC target("avx2") 
static const int _ = []() { 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    return 0;
}();

class Solution {
public:
    int xth(vector<int>& freq, int x){
        int count = 0;

        for(int i = 0; i < 50; i++){
            count += freq[i];
            if(count >= x){
                return i - 50;
            }
        }

        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int n = nums.size();
        vector<int> res;
        vector<int> freq(50,0);

        for(int i = 0; i < k; i++){
            if(nums[i] < 0){
                freq[nums[i] + 50]++;
            }
        }

        res.push_back(xth(freq,x));

        for(int i = k; i < n; i++){

            if(nums[i-k] < 0)
                freq[nums[i-k] + 50]--;

            if(nums[i] < 0)
                freq[nums[i] + 50]++;

            res.push_back(xth(freq,x));
        }

        return res;
    }
};
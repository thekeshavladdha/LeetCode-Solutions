class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> count;
        
        int limit = cbrt(n) + 1;
        
        for(int a=1; a<=limit; a++){
            for(int b=a; b<=limit; b++){
                
                long long sum = 1LL*a*a*a + 1LL*b*b*b;
                
                if(sum > n) break;
                
                count[sum]++;
            }
        }

        vector<int> ans;

        for(auto &[num, freq] : count){
            if(freq >= 2)
                ans.push_back(num);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
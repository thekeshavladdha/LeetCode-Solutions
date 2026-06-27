class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        long long count=0;
        
        for(auto& num:nums){
            if(num==digit){
                count++; 
                continue;
            }
            while(num>0){
                
                if(num%10==digit){ 
                    count++;
                }
                num/=10;
            }
        }
        return count;
    }
};
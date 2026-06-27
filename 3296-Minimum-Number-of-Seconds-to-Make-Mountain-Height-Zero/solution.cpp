class Solution {
public:
    bool removedfull(long long T,int mountainHeight, vector<int>& workerTimes ){
        long long total=0;
        for(int x:workerTimes){
            long long k=T/x*2;
            long long m=(-1+sqrt(1+4*k))/2;
            total+=m;
        }
        if(total>=mountainHeight){
            return true;
            }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start=2;
        long long minTime = *min_element(workerTimes.begin(), workerTimes.end());
        long long end = (long long)minTime * mountainHeight * (mountainHeight + 1) / 2;
        long long mid;
        if(mountainHeight==1){
            return minTime;
        }
        while(start<end){
            mid=start+(end-start)/2;
            if(removedfull(mid,mountainHeight,workerTimes)){
                end=mid;
            }
            else{
                start=mid+1;
            }

        }
        return end;

    }
};
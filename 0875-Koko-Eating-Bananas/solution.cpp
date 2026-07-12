class Solution {
private:
    long long hours(vector<int>& piles,int speed){
        long long h=0;
        for(int i=0;i<piles.size();i++){
            h+=piles[i]/speed;
            if(piles[i]%speed!=0) h++;
        }
        return h;
    }
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int res=0;
        int low=1,high=*max_element(piles.begin(),piles.end());
        
        while(low<=high){
            int speed=low+(high-low)/2;
            long long hour=hours(piles,speed);
            if(hour<=h){
                res=speed;
                high=speed-1;
            }
            else low=speed+1;
        }
        return res;
    }
};
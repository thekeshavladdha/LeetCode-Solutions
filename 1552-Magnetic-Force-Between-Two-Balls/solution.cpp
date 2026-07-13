class Solution {
public:
    int checkforce(vector<int>& position, int& mid, int& m){
        int i=0,j=1,dist=0;
        int count=1;
        while(j<position.size()){
            if((position[j]-position[i])>=mid){
                i=j;
                count++;
            }
            j++;
        }
        if(count>=m){
            return 1;
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int& m) {
        sort(position.begin(),position.end());
        int low=1,high=(position.back()-position.front())/(m-1), res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
        
            if(!checkforce(position,mid,m)){
                
                high=mid-1;
            }
            else{
                res=mid;
                low=mid+1;
            }
        }
        return res;
    }
};
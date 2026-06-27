class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int st1=intervals[0][0],en1=intervals[0][1],st2,en2,count=0;
        for(int i=1;i<intervals.size();i++){
            st2=intervals[i][0];
            en2=intervals[i][1];
            if(en1>=en2){
                count++;
                
                en1=en1;
                continue;
            }
            else if(st1==st2){
                count++;
                
                en1=max(en1,en2);
                continue;
            }
            st1=st2;
            en1=en2;
        }
        return intervals.size()-count;
    }
};
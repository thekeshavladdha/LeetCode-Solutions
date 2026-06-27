class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int start2,end2;
        for(int i=1;i<intervals.size();i++){
            start2=intervals[i][0];
            end2=intervals[i][1];

            if(end>=start2){
                start=start;
                end=max(end,end2);
                continue;
            }
            res.push_back({start,end});
            start=start2;
            end=end2;
        }
        res.push_back({start,end});
        return res;
    }
};
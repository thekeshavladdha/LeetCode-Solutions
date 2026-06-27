class Solution {
public:
    void merge(vector<vector<int>>& intervals, vector<int>& newInterval, vector<vector<int>>& res){
        int start=intervals[0][0];
        int end=intervals[0][1];
        int start2,end2;
        for(int i=0;i<intervals.size();i++){
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

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto it=lower_bound(intervals.begin(),intervals.end(),newInterval);
        intervals.insert(it,newInterval);
        merge(intervals, newInterval, res);
        return res;    
    }
};
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i=0,j=0;
        vector<vector<int>> res;
        int n=series1.size(),m=series2.size();
        while(i<n || j<m){
            int t;
            if(i==n && j<m){
                t=series2[j][0];
            }
            else if(j==m && i<n){
                t=series1[i][0];
            }
            else{
                t=min(series1[i][0],series2[j][0]);
            }
            int x=0,y=0;
            if(i<n && series1[i][0]==t){
                x=series1[i][1];
                i++;
            }
            if(j<m && series2[j][0]==t){
                y=series2[j][1];
                j++;
            }
            if(x==0 && i<n) x=series1[i][1];
            if(y==0 && j<m) y=series2[j][1];
            res.push_back({t,x+y});
        }
        return res;
    }
};
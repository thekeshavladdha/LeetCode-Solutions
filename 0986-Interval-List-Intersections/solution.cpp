class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        if (!firstList.size() || !secondList.size())
            return {};
        vector<vector<int>> res;
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        int start1, start2, end1, end2, a, b;
        while (i < n && j < m) {
            start1 = firstList[i][0];
            end1 = firstList[i][1];
            start2 = secondList[j][0];
            end2 = secondList[j][1];

            a = max(start1, start2);
            b = min(end1, end2);
            if (a <= b)
                res.push_back({a, b});
            end1 >= end2 ? j++ : i++;
            continue;
        }
        return res;
    }
};
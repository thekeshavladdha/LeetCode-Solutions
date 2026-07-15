class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, int> mp;

        priority_queue<pair<int, int>> hp;

        for (int i = 0; i < points.size(); i++) {

            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];

            if (hp.size() < k) {
                hp.push({dist, i});
            } else if (dist < hp.top().first) {
                hp.pop();
                hp.push({dist, i});
            }
        }
        vector<vector<int>> res;
        while (!hp.empty()) {
            res.push_back(points[hp.top().second]);
            hp.pop();
        }
        return res;
    }
};
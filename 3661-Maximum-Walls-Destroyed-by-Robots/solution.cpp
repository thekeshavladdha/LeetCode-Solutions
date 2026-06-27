class Solution {
public:
    typedef pair<int, int> P;
    int countWalls(vector<int>& walls, int left, int right) {
        return upper_bound(walls.begin(), walls.end(), right) -
               lower_bound(walls.begin(), walls.end(), left);
    }
    int solve(vector<P>& robotDist, vector<P>& range, int idx, int prevDir,
              vector<int>& walls, vector<vector<int>>& dp) {
        if (idx == robotDist.size())
            return 0;
        if(dp[idx][prevDir]!=-1) return dp[idx][prevDir];
        int go_left = range[idx].first;
        if (prevDir == 1 && idx > 0) {
            go_left = max(range[idx - 1].second+1, go_left);
        }
        int take_left = countWalls(walls, go_left, robotDist[idx].first) +
                        solve(robotDist, range, idx + 1, 0, walls,dp);
        int take_right =
            countWalls(walls, robotDist[idx].first, range[idx].second) +
            solve(robotDist, range, idx + 1, 1, walls,dp);
        return dp[idx][prevDir] = max(take_left, take_right);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<P> robotDist(n);
        vector<vector<int>> dp(n,vector<int>(2,-1));
        for (int i = 0; i < n; i++) {
            robotDist[i] = {robots[i], distance[i]};
        }
        sort(begin(robotDist), end(robotDist));
        sort(begin(walls), end(walls));
        vector<P> range(n);
        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? 1 : robotDist[i - 1].first + 1;
            int right = (i == n - 1) ? 1e9 : robotDist[i + 1].first - 1;

            int RangeLEFT = robotDist[i].first - robotDist[i].second;
            int RangeRIGHT = robotDist[i].first + robotDist[i].second;
            int L = max(left, RangeLEFT);
            int R = min(right, RangeRIGHT);
            range[i] = {L, R};
        }
        return solve(robotDist, range, 0, 0, walls,dp);
    }
};
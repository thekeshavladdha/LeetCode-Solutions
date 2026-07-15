class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto& it : words) {
            mp[it]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> hp;
        for (auto& [y,x]:mp) {
            if (hp.size() < k) {
                hp.push({x, y});
            } else {
                if (x > hp.top().first ||
                    (x == hp.top().first && y < hp.top().second)) {
                    hp.pop();
                    hp.push({x, y});
                }
            }
        }
        vector<string> res(hp.size());
        int i = hp.size() - 1;
        while (!hp.empty()) {
            res[i--] = hp.top().second;
            hp.pop();
        }
        return res;
    }
};
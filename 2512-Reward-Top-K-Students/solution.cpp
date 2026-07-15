class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    };
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {
        unordered_map<string, int> mp;
        for (auto& it : positive_feedback) {
            mp[it] = 3;
        }
        for (auto& it : negative_feedback) {
            mp[it] = 1;
        }

        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       cmp>
            hp;
        for (auto& words : report) {
            int score = 0;
            stringstream ss(words);
            string word;
            while (ss >> word) {
                if (mp.count(word)) {
                    score += (mp[word] == 3 ? 3 : -1);
                }
            }
            res.push_back(score);
        }
        for (int i = 0; i < res.size(); i++) {
            int x = student_id[i];
            int y = res[i];
            if (hp.size() < k)
                hp.push({y, x});
            else {
                if (y > hp.top().first) {
                    hp.pop();
                    hp.push({y, x});
                } else if (y == hp.top().first && x < hp.top().second) {
                    hp.pop();
                    hp.push({y, x});
                }
            }
        }
        vector<int> ans(hp.size());
        int i=hp.size()-1;
        while (!hp.empty()) {
            ans[i--]=hp.top().second;
            hp.pop();
        }
        
        return ans;
    }
};
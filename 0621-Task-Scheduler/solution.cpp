class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;
        for (auto& task : tasks) {
            mp[task]++;
        }
        unordered_map<char,int> reg;
        priority_queue<pair<int, char>> hp;
        for (auto& [x, y] : mp) {
            hp.push({y, x});
            reg[x] = 1;
        }
        int interval = 0;
        vector<pair<int, char>> waiting;
        while (!hp.empty()) {
            pair<int, char> curr = hp.top();
            hp.pop();
            if (interval == 0 || reg[curr.second] <= interval) {
                interval++;
                reg[curr.second] = interval+n;
                curr.first--;
                if (curr.first != 0) {
                    hp.push(curr);
                }
            } else {
                waiting.push_back(curr);
                int x=interval;
                while (x==interval && !hp.empty()) {
                    pair<int, char> curr2 = hp.top();
                    hp.pop();
                    if (reg[curr2.second] <= interval) {
                        interval++;
                        reg[curr2.second] = interval+n;
                        curr2.first--;
                        if (curr2.first != 0) {
                            hp.push(curr2);
                        }
                    }
                    else{
                        waiting.push_back(curr2);
                    }
                }
                if(x==interval) interval++;
                for(auto& x:waiting){
                    hp.push(x);
                }
                waiting.clear();
            }

        }
        return interval;
    }
};
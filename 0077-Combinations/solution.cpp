class Solution {
public:
    void comb(int n, int k, vector<vector<int>>& res, vector<int>& temp,int idx) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        
        for (int i = idx; i <= n; i++) {
            
            
            temp.push_back(i);
            comb(n, k, res, temp,i+1);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        int idx=1;
        
        comb(n, k, res, temp,idx);
        return res;
    }
};
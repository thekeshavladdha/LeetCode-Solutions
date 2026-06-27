class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<unordered_set<int>> row(n), col(n);  // ✅

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(row[i].count(matrix[i][j]) || 
                   col[j].count(matrix[i][j])) return false;

                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        }
        return true;
    }
};
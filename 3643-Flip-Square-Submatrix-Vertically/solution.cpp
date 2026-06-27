class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int temp;
        int bottom = x+k-1;
        for (int i = x; i < (x + k/2); i++) {
            for (int j = y; j < (y + k); j++) {
                temp = grid[i][j];
                
                grid[i][j] = grid[bottom][j];
                grid[bottom][j] = temp;
               
            }
            bottom--;
        }
        return grid;
    }
};
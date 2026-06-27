class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }
        
        if(total % 2 != 0) return false;
        
        
        long long running = 0;
        for(int i = 0; i < m; i++){
            long long row = 0;
            for(int j = 0; j < n; j++){
                row += grid[i][j];
            }
            
            running += row;
            
            if(running * 2 == total) return true;
        }
        
        
        running = 0;
        for(int j = 0; j < n; j++){
            long long col = 0;
            for(int i = 0; i < m; i++){
                col += grid[i][j];
            }
            
            running += col;
            
            if(running * 2 == total) return true;
        }
        
        return false;
    }
};
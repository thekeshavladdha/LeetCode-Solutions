class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        const long long mod=1e9+7;
        vector<vector<long long>> dpMAX(m,vector<long long>(n));
        vector<vector<long long>> dpMIN(m,vector<long long>(n));
        dpMAX[0][0] = dpMIN[0][0] =grid[0][0];
        for(int i=1;i<m;i++){
            dpMAX[i][0]=dpMAX[i-1][0]*grid[i][0];
            dpMIN[i][0]=dpMIN[i-1][0]*grid[i][0];
        }
        for(int j=1;j<n;j++){
            dpMIN[0][j]=dpMIN[0][j-1]*grid[0][j];
            dpMAX[0][j]=dpMAX[0][j-1]*grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int g=grid[i][j];
                dpMAX[i][j]=max({dpMAX[i][j-1]*g,dpMAX[i-1][j]*g,dpMIN[i][j-1]*g,dpMIN[i-1][j]*g});
                dpMIN[i][j]=min({dpMAX[i][j-1]*g,dpMAX[i-1][j]*g,dpMIN[i][j-1]*g,dpMIN[i-1][j]*g});
            }
        }
        return dpMAX[m-1][n-1]<0?-1:dpMAX[m-1][n-1]%mod;

    }
};
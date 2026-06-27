class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> reshaped(r,vector<int>(c));
        if(r*c!=m*n) return mat;
        int traverse=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                reshaped[traverse/c][traverse%c]=mat[i][j];
                traverse++;
            }
        }
        return reshaped;
    }
};
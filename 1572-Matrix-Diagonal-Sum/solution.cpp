class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1) return mat[0][0];
        int n=mat.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
            if(n%2!=0 && i==n/2) continue;
            sum+=mat[i][n-i-1];
        }
        return sum;
    }
};
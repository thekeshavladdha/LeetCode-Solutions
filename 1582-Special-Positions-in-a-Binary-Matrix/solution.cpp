class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        
        vector<int> rowcount(mat.size(),0);
        vector<int> colcount(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    rowcount[i]++;
                    colcount[j]++;
                }

            }
        }
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && rowcount[i]==1 && colcount[j]==1) count++;
            }
        }
        return count;
    }
};
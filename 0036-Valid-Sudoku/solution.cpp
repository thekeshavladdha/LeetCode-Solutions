class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> freq;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string row="row"+to_string(i)+to_string(board[i][j]);
                string col="col"+to_string(j)+to_string(board[i][j]);
                string square="square"+to_string(i/3)+to_string(j/3)+to_string(board[i][j]);
                if(freq.count(row) || freq.count(col) || freq.count(square)) return false;
                freq.insert(row);
                freq.insert(col);
                freq.insert(square);
                
            }
        }
        return true;
    }
};
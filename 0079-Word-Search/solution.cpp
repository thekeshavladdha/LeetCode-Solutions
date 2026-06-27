class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int i ,int j,int k){
        if(k==word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || i< 0|| j<0 ||board[i][j]!=word[k]) return false;
        char temo=board[i][j];
        board[i][j]='&';
        bool res= solve(board,word,i+1,j,k+1) || solve(board,word,i-1,j,k+1) || solve(board,word,i,j+1,k+1) || solve(board,word,i,j-1,k+1);
        board[i][j]=temo;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()>board.size()*board[0].size()) return false;
        unordered_map<char,int> freq;
        
        for(auto row: board){
            for(auto c: row){
                freq[c]++;
            }
        }
        for(auto chr: word){
            if(--freq[chr]<0) return false;
        }
        freq.clear();
        for(auto chr:word){
            freq[chr]++;
        }
        if(freq[word.front()]>freq[word.back()]){
            reverse(word.begin(),word.end());
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(board[i][j]==word.front()){
                    if(solve(board,word,i,j,0)) return true;
               } 
            }
        }
        return false;
    }
};
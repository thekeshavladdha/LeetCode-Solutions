class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size()/rows;
        vector<vector<char>> grid(rows,vector<char>(cols));
        int k=0;
        string res="";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j]=encodedText[k];
                k++;
            }
        }
        for(int j=0;j<cols;j++){
            int i=0;
            int k=j;
            while(i<rows && k<cols){
                res+=grid[i][k];
                i++;
                k++;
            }

        }
        while(!res.empty() && res.back()==' ') res.pop_back();

        return res;
    }
};
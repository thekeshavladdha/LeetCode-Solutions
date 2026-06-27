class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0;
        int bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        vector<int> sum;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                sum.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                sum.push_back(matrix[i][right]);
            }
            right--;
            if (bottom >= top) {
                for (int i = right; i >= left; i--) {
                    sum.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    sum.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return sum;
    }
};
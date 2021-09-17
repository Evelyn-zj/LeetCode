class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int number = 1;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                matrix[i][j] = number++;
            }
            for (int j = i + 1; j < n - i; ++j) {
                matrix[j][n - i - 1] = number++;
            }
            for (int j = n - i - 2; j >= i; --j) {
                matrix[n - i - 1][j] = number++;
            }
            for (int j = n - i - 2; j > i; --j) {
                matrix[j][i] = number++;
            }
        }
        return matrix;
    }
};
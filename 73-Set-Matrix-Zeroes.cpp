class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // declare two arrays of size n & m
        int n = matrix.size();
        int m = matrix[0].size();
        int col_0 = 1;
        // traverse the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    // mark the ith row
                    matrix[i][0] = 0; // row marker
                    // mark the jth col
                    if (j != 0) {
                        matrix[0][j] = 0; // col marker
                    } else {
                        col_0 = 0;
                    }
                }
            }
        }
        // traverse the matrix after marking to make the portion -> 0 (1,1) to (n-1 , m-1)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if ((matrix[i][0] == 0 || matrix[0][j] == 0))
                        matrix[i][j] = 0;
                }
            }
        }
        // modify the col-checker
        if (matrix[0][0] == 0) {
            for (int j=1;j<m;j++) {
                matrix[0][j] = 0;
            }
        }
        // modify the row-checker
        if (col_0 == 0) {
            for (int i=0; i<matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
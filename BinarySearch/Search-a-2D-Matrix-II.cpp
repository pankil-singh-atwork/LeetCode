class Solution {
public:
    // optimal approach -> fiing the top right corner & moving 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int right = matrix[top].size() - 1; // m - 1
        int n = matrix.size(); 
        // traverse the matrix 
        while (top <= n-1 && right >= 0) {
            // keep finding the element
            if (target < matrix[top][right]) {
                // move left
                --right;
            } else if (target > matrix[top][right]) {
                // move down
                ++top;
            } else {
                return true;
            }
        }
        return false;
    }
};
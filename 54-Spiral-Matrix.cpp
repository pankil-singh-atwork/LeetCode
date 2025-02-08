class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0, left = 0, right = matrix[0].size() - 1,
            bottom = matrix.size() - 1;
        int n = matrix.size(), m = matrix[0].size();
        while (left <= right && top <= bottom) {
            // left -> right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            // top -> bottom
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            // right -> left -> edge condition for single row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            // bottom -> top -> edge condition for single column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return res;
    }
};
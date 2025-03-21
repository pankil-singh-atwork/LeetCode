class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Optimal Approach - Using Binary Search
        int low = 0;
        int high = mat[0].size() - 1;
        while (low <= high) {
            // finding the mid
            int mid = (low + high) / 2;
            // find max index in this column -> mid
            int maxElement = INT_MIN;
            int maxRow = -1;
            for (int i=0; i<mat.size(); ++i) {
                if (mat[i][mid] > maxElement) {
                    maxElement = mat[i][mid];
                    maxRow = i;
                }
            }
            // initialize left & right
            int left = mid - 1 >= 0 ? mat[maxRow][mid-1] : -1; // checked out of bound
            int right = mid + 1 < mat[0].size() ? mat[maxRow][mid + 1] : -1; // checked out of bound
            // binary search logic
            if (left > mat[maxRow][mid]) {
                // eliminate right half
                high = mid - 1;
            } else if (right > mat[maxRow][mid]) {
                // eliminate left half
                low = mid + 1;
            } else {
                return {maxRow , mid};
            }
        }
        // DUMMY STATEMENT
        return {-1 , -1};
    }
};
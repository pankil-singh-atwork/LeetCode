class Solution {
public:
    // optimal solution
    vector<int> generateRow(int nrows) {
        vector<int> res;
        res.push_back(1);
        int ans = 1;
        for (int i=1;i<nrows;i++) {
            // calculating the numerator
            ans *= nrows - i;
            // calculating the denominator
            ans /= i;
            res.push_back(ans);
        }
        return res; 
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            int row = i+1;
            res.push_back(generateRow(row));
        }
        return res;
    }
};
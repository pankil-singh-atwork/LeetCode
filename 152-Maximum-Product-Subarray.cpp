class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Optimal Solution
        int n = nums.size();
        int maxProduct = INT_MIN;
        int prefixProduct = 1;
        int suffixProduct = 1;
        for (int i=0;i<n;++i) {
            prefixProduct *= nums[i];
            suffixProduct *= nums[n-(i+1)];
            maxProduct = max(maxProduct , prefixProduct);
            maxProduct = max(maxProduct , suffixProduct);
            if (nums[i] == 0) prefixProduct = 1;
            if (nums[n-(i+1)] == 0) suffixProduct = 1;
        }
        return maxProduct;
    } 
};
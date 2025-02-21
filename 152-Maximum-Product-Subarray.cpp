class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int prefixProduct = 1;
        int suffixProduct = 1;
        for (int i=0;i<nums.size();++i) {
            prefixProduct *= nums[i];
            maxProduct = max(maxProduct , prefixProduct);
            if (nums[i] == 0) prefixProduct = 1;
        }
        for (int j=nums.size()-1; j>=0; --j) {
            suffixProduct *= nums[j];
            maxProduct = max(maxProduct , suffixProduct);
            if (nums[j] == 0) suffixProduct = 1;
        }
        return maxProduct;
    } 
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // using two pointer -> optimal approach
        set<vector<int>> res;
        int n = nums.size();
        // two-pointer approach
        sort(nums.begin() , nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                // find target
                int target = nums[i] + nums[j] + nums[k];
                if (target < 0) {
                    j++;
                } else if (target > 0) {
                    k--;
                } else {
                    // generate the triplet
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.insert(temp);
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
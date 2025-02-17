class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // using two pointer(without set data structure) -> optimal approach
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // two-pointer approach
        for (int i = 0; i < n - 2; i++) {
            // condition to skip the duplicate ith element -> triplets
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
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
                    // generate the unique triplet
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // condition to skip the duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
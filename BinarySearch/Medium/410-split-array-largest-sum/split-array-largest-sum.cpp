class Solution {
public:
    int formSubarrayRange(vector<int>& nums , int range) {
        int sum = 0;
        int subArray = 0;

        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum > range) {
                ++subArray;
                sum = nums[i];
            }
        }
        if (sum <= range) ++subArray;
        return subArray;
    }
    int splitArray(vector<int>& nums, int k) {
        // range selection for the sum
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);

        while (low <= high) {
            // pass the limit range of sum to the function 
            int mid = (low + high) / 2;
            int count = formSubarrayRange(nums , mid);
            // apply binary search logic
            if (count <= k) {
                // decrease the range -> more or k subarray can be formed
                high = mid - 1;

            } else {
                // increaase the range -> count of subarray is less
                low = mid + 1;
            }
        }
        return low;
    }
};
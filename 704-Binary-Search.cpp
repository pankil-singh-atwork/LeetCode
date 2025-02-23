class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            // find mid 
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                // update low
                low = mid + 1;
            } else if (nums[mid] > target) {
                // update high
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
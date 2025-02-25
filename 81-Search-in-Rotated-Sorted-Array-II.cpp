class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // most optimal solution -> logn
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {
                // check for duplicates
                if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                    // we need to find the sorted region without conflict
                    ++low;
                    --high;
                    continue;
                }
                // if left half is sorted
                if (nums[low] <= nums[mid]) {
                    // if target in the sorted portion -> low <= target <=
                    // nums[mid]
                    if (nums[low] <= target && target < nums[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                // if right half is sorted
                if (nums[high] >= nums[mid]) {
                    if (nums[mid] < target && target <= nums[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            } else {
                return true;
            }
        }
        return false;
    }
};
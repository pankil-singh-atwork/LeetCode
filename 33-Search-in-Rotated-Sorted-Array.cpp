class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high , int target) {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
        return binarySearch(nums, low, high , target);
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != target) {
                // if left half is sorted
                if (nums[low] <= nums[mid]) {
                    int index = binarySearch(nums, low, mid , target);
                    if (index != -1)
                        return index;
                    else {
                        low = mid + 1;
                    }
                }
                // if right half is sorted
                if (nums[high] >= nums[mid]) {
                    int index = binarySearch(nums, mid, high , target);
                    if (index != -1)
                        return index;
                    else {
                        high = mid - 1;
                    }
                }
            } else {
                return mid;
            }
        }
        return -1;
    }
};
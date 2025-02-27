class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // if my mid is the answer no need to search more
            if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            // if mid -> odd
            if (mid % 2 != 0) {
                // odd -> even parity -> search on left half
                if (nums[mid + 1] == nums[mid])
                    high = mid - 1;
                // even -> odd parity -> search on right half
                else
                    low = mid + 1;
            } else {
                // even -> odd parity -> search on right half
                if (nums[mid] == nums[mid + 1])
                    low = mid + 2;
                // odd -> even parity -> search on left half
                else
                    high = mid - 2;
            }
        }
        return nums[low];
    }
};
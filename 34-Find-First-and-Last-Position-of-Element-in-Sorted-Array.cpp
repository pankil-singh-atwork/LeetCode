class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1 , last = -1;
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        // perform binary-search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
            else {
                // if single target 
                first = last = mid;
                int left = mid - 1 , right = mid + 1;
                // while traversing at left if we can find the target still
                while (left >= 0 && nums[left] == target) {
                    first = left;
                    --left;
                }
                // while traversing at right if we can still find the target
                while (right <= n-1 && nums[right] == target) {
                    last = right;
                    ++right;
                }
                break;
            }
        }
        return {first , last};
    }
};
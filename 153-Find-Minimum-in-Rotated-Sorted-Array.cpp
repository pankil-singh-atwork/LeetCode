class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int min = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                // BREAK- POINT in the range mid + 1 -> high
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // break - point in the range left -> mid
                right = mid;
            } else {
                min = nums[mid];
                break;
            }
        }
        return min;
    }
};
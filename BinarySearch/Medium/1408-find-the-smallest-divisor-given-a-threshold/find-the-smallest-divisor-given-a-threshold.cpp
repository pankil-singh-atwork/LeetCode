class Solution {
public:
    int sumDivisor(vector<int>& nums , int divisor) {
        int sum = 0;
        for (int i=0 ;i<nums.size(); ++i) {
            // ensures ceil value is rerturned
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = *max_element(nums.begin() , nums.end());
        // divisor range
        int low = 1;
        int high = max;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = sumDivisor(nums , mid);
            if (sum <= threshold) {
                // look for smaller divisor to get the larger value 
                high = mid - 1;
            } else {
                // look for higher divisor -> to get the minimum value
                low = mid +1;
            }
        }
        return low;
    }
};
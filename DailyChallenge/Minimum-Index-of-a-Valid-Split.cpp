class Solution {
public:
    // dominant codition -> x -> count(x) > n / 2 or count(x) * 2 > n
    // approach
    // find dominant in the nums array using hashmap -> <element , frequency> =
    // x find x count in subarray 1 & 2 for length n1 & n2 & check dominant
    // condition -> use another hashset if both satisfy return the minimum index
    // -> subarray1
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int maxFreq = 0, element = -1;
        for (int i = 0; i < n; ++i) {
            // count frequency
            mpp[nums[i]]++;
        }

        // traverse the map to find the dominant element 
        for (auto& [num , count] : mpp) {
            if (count > n / 2 ) {
                element = num;
                maxFreq = count;
                break;
            }
        }
        // count x -> n1 subarray & check for dominant in both subarrays (n1
        // & n2)
        int f1 = 0; // initialize left count;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int n1 = i + 1;
            int n2 = n - n1;
            if (nums[i] == element) {
                ++f1; // increment the leftcount
            }
            // calculate the right count
            int f2 = maxFreq - f1;
            // check dominant in both subarray
            if (f1 * 2 > n1 && f2 * 2 > n2) return i;
        }
        return -1;
    }
}
;
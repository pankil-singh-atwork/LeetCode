class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // my - approach -> binary search -> optimal
        int low = 0;
        int high = arr.size() - 1;
        // apply binary search -> logn
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            // obs-1 :- miss < k -> update low
            if (missing < k) low = mid + 1;
            else high = mid - 1;
        }
        return k + high + 1;
    }
};
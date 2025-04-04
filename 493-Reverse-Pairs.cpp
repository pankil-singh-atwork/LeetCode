class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner//
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    int inversionCount(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int count = 0;
        for (int left = low; left <= mid; ++left) {
            while (right <= high && arr[left] > 2ll * arr[right]) {
                ++right;
            }
            // update the count
            count += right - (mid + 1);
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);        // left half
        cnt += mergeSort(arr, mid + 1, high);   // right half
        cnt += inversionCount(arr, low, mid, high); // Modification
        merge(arr, low, mid, high);             // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

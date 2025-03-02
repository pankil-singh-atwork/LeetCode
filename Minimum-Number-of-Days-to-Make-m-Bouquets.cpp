class Solution {
public:
    int countAdjacentPairs(vector<int>& days, int k, int day) {
        int count = 0;
        int pair = 0;
        for (int i = 0; i < days.size(); ++i) {
            if (days[i] > day) {
                // set count to zero
                count = 0;
                continue;
            }
            ++count;
            if (count % k == 0)
                ++pair;
        }
        return pair;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int minElement = *min_element(bloomDay.begin() , bloomDay.end());
        int maxElement = *max_element(bloomDay.begin() , bloomDay.end());
        int low = minElement;
        int high = maxElement;
        // handling edge cases
        if ((long long) m * k > n) return -1;
        // simple binary search
        while (low <= high) {
            // current day
            int mid = (low + high) / 2;
            int bouquet = countAdjacentPairs(bloomDay , k , mid);
            if (bouquet < m) {
                // wait for more day
                low = mid + 1;
            } else {
                // wait for minimum day
                high = mid - 1;
            }
        }
        return low;
    }

};
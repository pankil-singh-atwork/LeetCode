class Solution {
public:
    int findMinimumDays(vector<int>& weights , int capacity) {
        int sum = 0 , days = 0;
        for (int i=0; i<weights.size(); ++i) {
            sum += weights[i]; 
            if (sum > capacity) {
                // ship the previous packages
                ++days;
                // reset the weight 
                sum = 0;
                sum += weights[i];
            }
        }
        if (sum <= capacity) ++days;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_capacity = accumulate(weights.begin() , weights.end() , 0);
        int max = *max_element(weights.begin() , weights.end());
        int low = max , high = max_capacity;
        while (low <= high) {
            int mid = (low + high) / 2;
            int minDay = findMinimumDays(weights , mid);
            if (minDay <= days) high = mid - 1; // decrease the capacity 
            else low = mid + 1; // increase the capacity
        }
        return low;

    }
};

class Solution {
public:
    long long timetakentoEat(vector<int>& piles, int k) {
        long long t = 0;
        for (int i = 0; i < piles.size(); ++i) {
            // bananas to eat 
            t += (piles[i] + k - 1LL) / k;
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // chose the value of k so that koko can eat all the bananas within the time t 
        int low = 1;
        int high = *max_element(piles.begin() , piles.end()); // max eating speed
        int speed = -1;
        // simple binary search logic 
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long time = timetakentoEat(piles , mid);
            // there can be some time which cannot be finished exactly on those cases return the best optimal time (minimum time)
            if (time <= h) {
                // decrease the speed
                speed = mid;
                high = mid - 1;
            } else {
                // koko has eaten very slowly
                // increase the speed;
                low = mid + 1;
            }
        }
        return speed;
    }
};
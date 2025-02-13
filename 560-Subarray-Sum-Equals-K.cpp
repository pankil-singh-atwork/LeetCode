class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // optimal approach
        unordered_map<int , int> mpp;
        int count = 0 , preSum = 0;
        mpp[0] = 1;
        for (int i=0;i<nums.size();i++) {
            // calculate the prefix sum
            preSum += nums.at(i);
            // calculate the previous prefix Sum required to get the subarray ie x - k
            int remove = preSum - k;
            // check if in the map at this iteration it's present or not
            if (mpp.find(remove) != mpp.end()) count += mpp[remove];
            // update the map <preSum , count> by 1
            mpp[preSum]++;
        }
        return count;
    }
};
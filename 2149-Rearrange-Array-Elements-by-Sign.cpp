class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // BruteForce Approach 
        vector<int> pos;
        vector<int> neg;
        for (int i=0; i<nums.size();i++) {
            if(nums.at(i) < 0) {
                neg.push_back(nums.at(i));
            } else {
                pos.push_back(nums.at(i));
            }
        }
        // merging back to the original array alternately by simultaneously traversing the both pos & neg array
        for(int i=0;i<nums.size()/2;i++) {
            nums.at(2*i) = pos.at(i);
            nums.at(2*i+1) = neg.at(i);
        }
        return nums;
    }
};
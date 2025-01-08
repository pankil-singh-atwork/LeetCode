class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // optimal approach
        vector<int> result(nums.size());
        int posi = 0 , negi = 1;
        for (int i=0;i<nums.size();i++) {
            if (nums.at(i) > 0) {
                result.at(posi) = nums.at(i);
                posi+=2;
            } else {
                result.at(negi) = nums.at(i);
                negi+=2;
            }
        }
        return result;
    }
};
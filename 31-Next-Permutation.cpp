class Solution {
public:
    int breakPoint(vector<int>& nums) {
        int bp = -1;
        for (int i=nums.size()-2;i>=0;i--) {
            if (nums.at(i) < nums.at(i+1)) {
                bp = i;
                break;
            }
        }
        return bp;
    }
    int smallestElementIndex(vector<int>& nums , int index) {
        int min = INT_MAX;
        int mini = -1;
        // find the smallest element just greater than break-point index;
        for (int i = index + 1; i<nums.size(); i++) {
            if (nums.at(i) < min && nums.at(i) > nums.at(index)) {
                min = nums.at(i);
                mini = i;
            }
        }
        return mini;
    }
    void nextPermutation(vector<int>& nums) {
        // find the brak-point index
        int index = breakPoint(nums);
        if (index == -1) {
            reverse(nums.begin() , nums.end());
        } else {
            int mini = smallestElementIndex(nums , index);
            swap(nums[index] , nums[mini]);
            sort(nums.begin() + index + 1 , nums.end());
        }

    }
};
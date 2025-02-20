class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // my approach 
        // resizing the vector
        // reduce the num1 vector by erasing n elements from the end
        nums1.resize(nums1.size() - n);
        // merge nums1 & nums2 -> nums1[] array
        for (int i=0;i<nums2.size();++i) {
            nums1.push_back(nums2[i]);
        }
        // sort the nums1[] array to arrange elements in sorted order
        sort(nums1.begin() , nums1.end());
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        vector<int> result;
        // insert unique elements -> 
        for(int i=0; i<nums1.size(); ++i) set1.insert(nums1[i]);
        for(int j=0; j<nums2.size();++j) set2.insert(nums2[j]);
        // finding common elements
        for(int num : set1) {
            if(set2.find(num) != set2.end()) {
                result.push_back(num);
            }
        }
        return result;
    }
};
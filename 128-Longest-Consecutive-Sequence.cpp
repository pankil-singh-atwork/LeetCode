class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // using ordered set
        if (nums.empty()) return 0;
        set<int> res(nums.begin() , nums.end());
        int longest = 0;
        int lcs = 1;
        for (auto it = next(res.begin()); it != res.end(); ++it) {
            auto prevIt = prev(it);
            if(*it == *prevIt + 1) ++lcs;
            else {
                // update the longest
                longest = max(longest , lcs);
                lcs = 1; 
            }
        }
        longest = max(longest , lcs);
        return longest;
    }
};
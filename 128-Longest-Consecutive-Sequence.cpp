class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // using brute-force approach
        if (nums.empty())
            return 0;
        // initalizing the set
        unordered_set<int> res(nums.begin(), nums.end());
        int longest = 0;
        for (auto it = res.begin(); it != res.end(); ++it) {
            // checking for only starting element of the sequence
            if (res.find(*it - 1) == res.end()) {
                int count = 1;
                // checking for consecutive next element
                int next = 1;
                while (res.find(*it + next) != res.end()) {
                    ++count;
                    ++next;
                }
                  // updating the max_count
                longest = max(count, longest); 
            }
        }
        return longest;
    }
};
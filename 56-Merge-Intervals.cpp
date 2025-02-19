class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        // sort the interval vector
        sort(intervals.begin() , intervals.end());
        // initalize initial temp<vector>
        vector<int> temp = intervals[0];
        for(int i=1;i<intervals.size();++i) {
            // if overlap then merge & updat the temp vector
            if (temp[1] >= intervals[i][0]) {
                temp[1] = max(temp[1] , intervals[i][1]);
            } else {
                // push the temp vector -> latest merged one  
                ans.push_back(temp);
                // updated the temp vector -> current interval for next check
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
class Solution {
    vector<vector<int>> newinterval;
    vector<vector<int>> ans;

private:

    void solve(vector<vector<int>>& intervals, vector<int>& newint) {

        

        for (int i = 0; i < intervals.size(); i++) {

            if (newint[0] < intervals[i][0]) {
                newinterval.push_back(newint);
                
            }

            newinterval.push_back(intervals[i]);
        }

        
        newinterval.push_back(newint);
    }

    void solve2(vector<vector<int>>& newinterval) {

        ans.push_back(newinterval[0]);

        for (int i = 1; i < newinterval.size(); i++) {

            if (ans.back()[1] >= newinterval[i][0]) {
                ans.back()[1] = max(ans.back()[1], newinterval[i][1]);
            }
            else {
                ans.push_back(newinterval[i]);
            }
        }
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        solve(intervals, newInterval);

        solve2(newinterval);

        return ans;
    }
};
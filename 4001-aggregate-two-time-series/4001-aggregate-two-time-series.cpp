class Solution {
private:
    int search(vector<vector<int>>& series, int target) {
        auto it = lower_bound(
            series.begin(),
            series.end(),
            target,
            [](const vector<int>& a, int value) {
                return a[0] < value;
            }
        );

        if (it == series.end())
            return 0;

        return (*it)[1];
    }

public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        set<int> times;

        for (auto &x : series1)
            times.insert(x[0]);

        for (auto &x : series2)
            times.insert(x[0]);

        vector<vector<int>> ans;

        for (int t : times) {
            int val1 = search(series1, t);
            int val2 = search(series2, t);

            ans.push_back({t, val1 + val2});
        }

        return ans;
    }
};
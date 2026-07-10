class Solution {

private:
vector<vector<int>> solve(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {

    vector<vector<int>> inter = solve(intervals);

    long long activeTime = 0;

    for (int i = 0; i < inter.size(); i++) {
        activeTime += 1LL * (inter[i][1] - inter[i][0] + 1);
    }

    long long bulbs = (brightness + 2) / 3;

    return bulbs * activeTime;
}
};
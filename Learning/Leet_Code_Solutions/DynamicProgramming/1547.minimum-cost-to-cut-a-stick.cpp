class Solution
{
private:
public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));

        int ans = helper(0, m + 1, cuts, dp);

        return ans;
    }

    int helper(int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // Base Case
        if ((start + 1) == end)
        {
            return 0;
        }

        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        int ans = INT_MAX;

        for (int i = start + 1; i < end; i++)
        {
            int cost = helper(start, i, cuts, dp) + helper(i, end, cuts, dp) + (cuts[end] - cuts[start]);
            ans = min(ans, cost);
        }

        return dp[start][end] = ans;
    }
};
class Solution
{
public:
    const int mod = 1e9 + 7;

    long long dp[105][205];

    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        memset(dp, -1, sizeof(dp));
        int ans = helper(start, finish, fuel, locations);

        return ans;
    }

    int helper(int start, int finish, int fuel, vector<int> &locations)
    {
        if (fuel < 0)
        {
            return 0;
        }
        int n = locations.size();

        if (dp[start][fuel] != -1)
        {
            return dp[start][fuel];
        }
        long long ans = 0;
        if (start == finish)
        {
            ans = 1;
        }

        // We are at start and we can move to any location we want if we have enough fuel to do so.
        for (int i = 0; i < n; i++)
        {
            if (i != start)
            {
                ans = (ans + helper(i, finish, fuel - abs(locations[i] - locations[start]), locations)) % mod;
            }
        }

        return dp[start][fuel] = ans;
    }
};
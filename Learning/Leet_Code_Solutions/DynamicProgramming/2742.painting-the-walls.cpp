class Solution
{
public:
    int dp[505][505];

    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        // Binary Search can't be applied.
        // Because we have to explore all the ways.

        // Typical - (take + not_take problem).

        // Inference - If we take a wall painted by a paid painter, then we can skip time[i] walls
        // Why? - Because they can be painted by free painter for 0 cost in 1 unit of time per each
        //        wall.

        // So here we can see the application of either selecting the current wall for the paid
        // painter or to skip it.
        int n = time.size();
        memset(dp, -1, sizeof(dp));
        int ans = findCost(cost, time, 0, n);

        return ans;
    }

    int findCost(vector<int> &cost, vector<int> &time, int i, int wallsRemaining)
    {
        int n = cost.size();
        if (wallsRemaining <= 0)
            return 0;

        if (i >= n)
        {
            return 1e9;
        }

        if (dp[i][wallsRemaining] != -1)
        {
            return dp[i][wallsRemaining];
        }

        // Either skip this wall to be painted by the paid painter.
        int skip = findCost(cost, time, i + 1, wallsRemaining);

        // Take it - cost if painted by the paid painter.
        int take = cost[i] + findCost(cost, time, i + 1, wallsRemaining - time[i] - 1);

        return dp[i][wallsRemaining] = min(take, skip);
    }
};
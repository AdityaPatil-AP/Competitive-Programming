
class Solution
{
public:
    int minimumTime(int N, int cur, vector<int> &pos, vector<int> &time)
    {
        int ans = 1e9;

        for (int i = 0; i < N; i++)
        {
            // Distance between taxi and me.
            int distance = abs(cur - pos[i]);
            // Total time taken by that taxi to reach me.
            // Time taken to board this taxi.
            int timeRequired = time[i] * distance;

            // We will update minimum time if possible.
            ans = min(ans, timeRequired);
        }

        // At the end, the answer variable will store the minimum time to board the
        // taxi.
        return ans;
    }
};
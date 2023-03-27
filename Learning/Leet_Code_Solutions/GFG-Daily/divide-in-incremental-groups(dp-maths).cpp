class Solution
{
public:
    int countWaystoDivide(int N, int K)
    {
        // Code here
        //

        // Time Complexity : O(N^3 * K).
        // dp[n][m][k] -> represents the number of ways to divide the number n into k ways, when
        // the last number chosen was m.
        // vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

        // filling up the base case.

        // thinking about the correct base cases.
        // if dp[0][anything][k] = 0;

        // if dp[n][m][1] = 1, if(n <= m).
        // else dp[n][m][1] = 0, if(n > m).

        // for(int i = 1;i <= N;i++){
        //     for(int j = 1;j <= N;j++){
        //         if(i <= j){
        //             dp[1][i][j] = 1;
        //         }
        //     }
        // }

        // dp[0][0][0] = 1;

        // for(int k = 2;k <= K;k++){
        //     for(int i = 1;i <= N;i++){
        //         for(int j = 1;j <= N;j++){

        //             for(int c = 1;c <= j;c++){
        //                 if((i - c) >= 0){
        //                     dp[k][i][j] += dp[k - 1][i - c][c];
        //                 }
        //             }

        //         }
        //     }
        // }

        // return dp[K][N][N];

        // Time Complexity : O(N^2 * K)
        int dp[N + 1][K + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= K; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;

        // If I have 'i' value, then i can take anything less than it.
        // Therefore, If i take the outer loop to be values that can be removed but for that the numbers
        // must be greater than them, so the inner of the numbers start from val till N.

        for (int val = 1; val <= N; val++)
        {
            for (int i = val; i <= N; i++)
            {
                for (int j = 1; j <= K; j++)
                {
                    dp[i][j] += dp[i - val][j - 1];
                }
            }
        }

        return dp[N][K];

        // Using recursion and memoisation.

        // vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (N + 1, vector<int>(K + 1, -1)));

        // return solve(N, K, N, dp);
    }

    int solve(int N, int K, int prev, vector<vector<vector<int>>> &dp)
    {
        if (K == 0)
        {
            if (N == 0)
                return 1;
            else
                return 0;
        }

        if (dp[N][prev][K] != -1)
        {
            return dp[N][prev][K];
        }

        int ways = 0;

        for (int i = 1; i <= min(N, prev); i++)
        {
            ways += solve(N - i, K - 1, i, dp);
        }

        return dp[N][prev][K] = ways;
    }
};
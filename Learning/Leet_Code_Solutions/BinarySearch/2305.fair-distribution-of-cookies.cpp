class Solution
{
public:
    int dfs(int i, vector<int> &distribute, vector<int> &cookies, int k, int zeroCount)
    {
        // If there are not enough cookies, return INT_MAX as it leads to an
        // invalid Distribution.
        // Early Stop Tecnhique.
        if (cookies.size() - i < zeroCount)
        {
            return 1e9;
        }

        // After distributing all cookies, return the unfairness of this
        // distribution.
        if (i == cookies.size())
        {
            return *max_element(distribute.begin(), distribute.end());
        }

        // Try to distribute the ith cookie to each child and update answer.
        // as the unfairness in these distributions.

        int answer = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            zeroCount -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[i];

            // Recursively distribute the next cookie.
            answer = min(answer, dfs(i + 1, distribute, cookies, k, zeroCount));

            distribute[j] -= cookies[i];
            zeroCount += distribute[j] == 0 ? 1 : 0;
        }

        return answer;
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        // Using Dynamic Programming and Bitmask.

        // dp[i][j] state -> Minimum value of unfairness for 0-i childrens when
        // bitmask of cookie bags is j.
        // where a bit of 1 means that a bag is used.

        // sum[j] is the sum of cookies when bit mask of cookie bags is j.

        // For the ith child, bit mask is j,
        // we can enumerate all the subsets of j as bag of cookies for ith
        // children, unfairness value of subset sub is sum[sub], and minimum
        // unfairness value of 0-(i - 1) children is dp[i - 1][sub^j].
        // where (sub^j) is to remove sub from j.

        // So, dp[i][j] = min(dp[i][j], max(sum[sub], dp[i - 1][j ^ sub]));

        // How to enumerate all subset of s of bitmask j.
        // sub = j -> (sub - 1) & j is always a subset of j for sub >= 0;

        int size = cookies.size();

        vector<vector<int>> dp(k, vector<int>(1 << size));
        vector<int> sum(1 << size);

        for (int i = 0; i < (1 << size); i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i >> j & 1)
                    sum[i] += cookies[j];
            }
        }

        dp[0] = sum;

        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < (1 << size); j++)
            {
                dp[i][j] = INT_MAX;
                for (int sub = j, max_cost; sub; sub = (sub - 1) & j)
                {
                    max_cost = max(dp[i - 1][j ^ sub], sum[sub]);
                    dp[i][j] = min(dp[i][j], max_cost);
                }
            }
        }

        return dp[k - 1].back();

        // Using Backtracking.
        // vector<int> distribute(k, 0);

        // // parameters.
        // // index, distribute vector, cookies array, k, zeroCount.
        // return dfs(0, distribute, cookies, k, k);

        // Binary Search.
        // sort(cookies.begin(), cookies.end());

        // int l = *max_element(cookies.begin(), cookies.end());
        // int r = 1e6;

        // while(l <= r){
        //     int m = (l + r)/2;
        //     if(possible(cookies, m, k)){
        //         r = m - 1;
        //     }
        //     else{
        //         l = m + 1;
        //     }
        // }

        // return (r + 1);
    }

    bool possible(vector<int> &cookies, int m, int k)
    {
        do
        {
            int curr = 0;
            int cnt = 0;

            for (int i = 0; i < cookies.size(); i++)
            {
                if (curr + cookies[i] > m)
                {
                    cnt++;
                    curr = cookies[i];
                }
                else
                    curr += cookies[i];
            }
            cnt++;

            if (cnt <= k)
                return 1;
        } while (next_permutation(cookies.begin(), cookies.end()));

        return 0;
    }
};
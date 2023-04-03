#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int main()
{

    // Checking for a possibility question.
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(1e5 + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int val = 0; val <= 1e5; val++)
        {
            // I take the ith index and add the sum.
            if (val - arr[i - 1] >= 0)
            {
                dp[i][val] = dp[i - 1][val - arr[i - 1]];
            }
            // or i decide to not take the current coin.
            dp[i][val] = (dp[i][val] || (dp[i - 1][val]));
        }
    }

    vector<int> ans;
    for (int i = 1; i <= 1e5; i++)
    {
        if (dp[n][i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
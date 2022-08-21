#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vc = vector<char>;
using vvc = vector<vc>;

int f(int d,int i, int j, vector<vector<char>> &grid, vector<vector<vector<int>>> &dp){
    // Base Case
    

    if(dp[d][i][j] != -1){
        return dp[d][i][j];
    }

    // Explorations
    int maxi = INT_MIN;
    if(grid[i][j] == 'X'){
        for(int ii = 0;ii < d;ii++){
            int maxi = max(maxi, f(ii, i, j, grid, dp));
        }
    } 
    return 0;
}

void work(){
    // int n;
    // cin >> n;
    // Rather than a 2-d vector for the indexes we may add another parameter 
    // for direction as well and convert this problem into 3d - dp.
    // vector<vector<vector<int>>> dp(8, vector<vector<int>>(n, vector<int> (n, -1)));
    // vector<vector<char>> grid(n, vector<char>(n, '.'));
    // for(int i = 0;i < n;i++){
    //     for(int j = 0;j < n;j++){
    //         cin >> grid[i][j];
    //     }
    // }
    // // for(int i = 0;i < n;i++){
    // //     for(int j = 0;j < n;j++){
    // //         cout << grid[i][j];
    // //     }
    // //     cout << endl;
    // // }
    // int ans = f(8,n - 1, n - 1, grid, dp);
    // cout << ans << endl;

    // Someone's Solution
    // int n;
    // cin>>n;
    // vvc g(n + 1,vc(n + 1));
    // vvvi dp(n + 2,vvi(n + 2,vi(8)));
    // vvi ans(n + 1,vi(n + 1));

    // for (int i = 1;i<=n;i++){
    //     for (int j = 1;j<=n;j++){
    //         cin>>g[i][j];
    //         if (g[i][j] == '.')continue;
            
    //         dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
    //         dp[i][j][1] = dp[i - 1][j][1] + 1;
    //         dp[i][j][2] = dp[i - 1][j + 1][2] + 1;
    //         dp[i][j][7] = dp[i][j - 1][7] + 1;
    //     }
    // }
    
    // for (int i = n;i>=1;i--){
    //     for (int j = n;j>=1;j--){
    //         if (g[i][j] == '.')continue;
    //         dp[i][j][3] = dp[i][j + 1][3] + 1;
    //         dp[i][j][4] = dp[i + 1][j + 1][4] + 1;
    //         dp[i][j][5] = dp[i + 1][j][5] + 1;
    //         dp[i][j][6] = dp[i + 1][j - 1][6] + 1;
    //     }
    // }
    // for (int i = 1;i<=n;i++){
    //     for (int j = 1;j<=n;j++){
            
    //         if (g[i][j] == '.'){
    //             cout<<0<<" ";
    //             continue;
    //         }

    //         ans[i][j] = max({
    //             dp[i][j][0] + dp[i + 1][j + 1][4],
    //             dp[i][j][1] + dp[i + 1][j][5],
    //             dp[i][j][2] + dp[i + 1][j - 1][6],
    //             dp[i][j][3] + dp[i][j - 1][7]});
            
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // Repeating his solution
    int n;
    cin >> n;
    vvc g(n + 1, vc(n + 1));
    vvvi dp(n + 2, vvi(n + 2, vi(8, 0)));
    vvi ans(n + 1, vi(n + 1, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> g[i][j];
            if(g[i][j] == '.') continue;

            dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
            dp[i][j][1] = dp[i - 1][j][1] + 1;
            dp[i][j][2] = dp[i - 1][j + 1][2] + 1;
            dp[i][j][7] = dp[i][j - 1][7] + 1;
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = n; j >= 1;j--){
            if(g[i][j] == '.') continue;
            dp[i][j][3] = dp[i][j + 1][3] + 1;
            dp[i][j][4] = dp[i + 1][j + 1][4] + 1;
            dp[i][j][5] = dp[i + 1][j][5] + 1;
            dp[i][j][6] = dp[i + 1][j - 1][6] + 1;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(g[i][j] == '.'){
                cout << 0 << " ";
                continue;
            }
            ans[i][j] = max(
                {dp[i][j][0] + dp[i + 1][j + 1][4],
                dp[i][j][1] + dp[i + 1][j][5],
                dp[i][j][2] + dp[i + 1][j - 1][6],
                dp[i][j][3] + dp[i][j - 1][7]}
                );
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



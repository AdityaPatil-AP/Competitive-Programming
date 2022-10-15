#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int t;
    cin >> t;
    for(int  k= 1;k <= t;k++){
        int n, m, p;
        cin >> m >> n >> p;
        int ans = 0;
        vector<vector<int>> arr(m, vector<int> (n, 0));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cin >> arr[i][j];
            }
        }
        vector<int> maxperday(n, 0);
        for(int i = 0;i < n;i++){
            int maxi = 0;
            for(int j = 0;j < m;j++){
                maxi = max(maxi ,arr[j][i]);
            }
            maxperday[i] = maxi;
        }
        for(int i = 0;i < n;i++){
            ans += (maxperday[i] - arr[p - 1][i]);
        }
        cout << "Case #" << k << ": " << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    // your code goes here
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        for(auto &x : arr) cin >> x;
        vector<ll> v(32, 0);
        vector<pair<ll, vector<ll>>> pc(n + 1);
        for(int i = 0;i <= n;i++){
            pc[i].second = v;
        }
        for(int i = 0;i < arr.size();i++){
            ll temp = arr[i];
            int count = 0;
            while(temp > 0){
                temp /= 2;
                count++;
            }
            pc[i + 1].second[count]++;
            for(int j = 0;j < 32;j++){
                pc[i + 1].second[j] += pc[i].second[j];
            }
        }
        ll q;
        cin >> q;
        while(q--){
            ll l, r, x;
            cin >> l >> r >> x;
            ll fsb = 0;
            while(x > 0){
                x = x/2;
                fsb++;
            }
            ll ans = 0;
            for(int j = 0;j < 32;j++){
                if(j == fsb){
                    continue;
                }
                else{
                    ans += pc[r].second[j] - pc[l - 1].second[j];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

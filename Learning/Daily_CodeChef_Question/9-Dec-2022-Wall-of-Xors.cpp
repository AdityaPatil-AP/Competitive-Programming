#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        for(auto &x : arr) cin >> x;
        vector<ll> odd;
        vector<ll> even;
        map<ll, ll> mp;
        for(int i = 0;i < n;i++){
            if(arr[i] % 2){
                odd.push_back(arr[i]);
            }
            else even.push_back(arr[i]);
            mp[arr[i]]++;
        }
       sort(odd.begin(), odd.end());
       sort(even.begin(), even.end());
       // Brute Force way.
       //ll ans = 0;
       // odd^odd = even
       //for(int i = 0;i < odd.size() - 1;i++){
       //    for(int j = i + 1;j < odd.size();j++){
       //        ll curr = odd[i] ^ odd[j];
       //        if(curr >= 4 && curr % 2 == 0){
       //            ans++;
       //        }
       //    }
       //}
       // even ^even = even;
       //for(int i = 0;i < even.size() - 1;i++){
       //    for(int j = i + 1;j < even.size();j++){
       //        ll curr = even[i] ^ even[j];
       //        if(curr >= 4 && curr % 2 == 0){
       //            ans++;
       //        }
       //    }
       //}
       //cout << ans << endl;
       
       // Efficient way.
       // Total pairs.
       ll ans = (((odd.size()) * (odd.size() - 1))) + (((even.size()) * (even.size() - 1)));
       //cout << ans << endl;
       for(auto m : odd){
           ans -= (mp[(m ^ 2)]);
           ans -= (mp[m] - 1);
       }
       //cout << ans << endl;
       for(auto m : even){
           ans -= (mp[(m ^ 2)]);
           ans -= (mp[m] - 1);
       }
       
       cout << ans/2 << endl;
    }
    return 0;
}

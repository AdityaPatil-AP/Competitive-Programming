#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
    int t;
    cin >> t;
    for(int  k= 1;k <= t;k++){
        int n;
        cin >>n;
        vector<int> arr(n, 0);
        for(auto &x : arr) cin >> x;
        int curr = 0;
        int usum = 0;
        int i = 0;
        int currsum = 0;
        while(i < n){
            curr += arr[i];
            if(curr < 0){
                curr = 0;
                currsum = 0;
            }
            else{ 
                currsum += curr;
                usum+=currsum;
            }
            i++;
        }
        if(curr > 0) usum += currsum;
        cout << "Case #" << k << ": " << usum << endl;
    }
    return 0;
}
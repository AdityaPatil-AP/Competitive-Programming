#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

void work(){
    // My Try :
    // Distinct Numbers
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> arr(n, 0);
    for(int &x : arr) cin >> x;
    int maxi = INT_MIN;
    for(int i = 0;i < n;i++){
        maxi = max(arr[i], maxi);
        st.insert(arr[i]);
    }


    set<int> st1 = st;
    // Choosing the max and then all the minimum;
    ll ans1 = 0;
    int size = st.size();
    int max1 = maxi;
    for(int i = 2 * size;i >= 1;i--){
        if(st.find(i) == st.end()){
            st.insert(i);
            max1 = i;
            break;
        }
    }
    size++;
    int maxm = max(maxi, max1);
    ans1 += (maxm - max1);
    int op = k - 1;
    for(int i = 1;i <= 2 * size, op > 0;i++){
        if(st.find(i) == st.end()){
            maxm = max(maxm, i);
            // cout << i << " " << maxm << endl;
            ans1 += (maxm - i);
            st.insert(i);
            op--;
        }
    }
    // Choosing the current max as the only max and choosing from the first.
    ll ans2 = 0;
    op = k;
    size = st1.size();
    for(int i = 1;i <= 2* size++,op > 0;i++){
        
        if(st1.find(i) == st1.end()){
            maxi = max(maxi, i);
            ans2 += (maxi - i);
            st1.insert(i);
            op--;
        }
    }
    cout << max(ans1, ans2) << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



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
    // Maximum Subarray
    int n;
    cin >> n;
    vector<int> arr1(n + 2, 0);
    for(int i = 1; i <= n;i++) cin >> arr1[i];
    int m;
    cin >> m;
    vector<int> arr2(m, 0);
    for(int i = 0;i < m;i++) cin >> arr2[i];
    int sum = 0;
    // Traverse in the second array and find the positive integers
    int maxElement = INT_MIN;
    for(int i = 0;i < m;i++){
        maxElement = max(arr2[i], maxElement);
        if(arr2[i] > 0){
            sum += arr2[i];
        }
    }
    // Putting all the positive elements at the start.
    arr1[0] = sum;
    int i = 0;
    int maxsum = INT_MIN;
    int sumn = 0;
    while(i < n + 1){
        sumn += arr1[i];
        if(sumn > maxsum){
            maxsum = sumn;
        }
        if(sumn < 0)
            sumn = 0;
        i++;
    }
    arr1[0] = 0;
    arr1[n + 1] = sum;
    sumn = 0;
    i = 0;
    while(i < n + 2){
        sumn += arr1[i];
        if(sumn > maxsum){
            maxsum = sumn;
        }
        if(sumn < 0)
            sumn = 0;
        i++;
    }
    cout << max(maxElement, maxsum) << endl;
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



#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


#define MAX 1000010
int arr[MAX];

void work(){
   // WA Test Cases
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    string V;
    cin >> V;
    int smallest_test_case = INT_MAX;
    for(int i = 0;i < n;i++){
        if(V[i] == '0'){
            smallest_test_case = min(smallest_test_case, arr[i]);
        }
    }
    cout << smallest_test_case << endl;
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



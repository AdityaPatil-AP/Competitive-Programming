#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


#define MAX 1000010
int arr[MAX];

void sieve(){
    for(int i = 0;i < MAX;i++){
        arr[i] = 0;
    }
    arr[2] = 0;
    for(int i = 2;i < MAX;i++){
        if(arr[i] == 0){
            arr[i] = 1;
            for(int j = 2 * i;j < MAX;j+=i){
                arr[j]++;
            }
        }
    }
    // for(int i = 2;i < 30;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}

void work(){
   int a, b, k;
   cin >> a >> b >> k;
   int cnt = 0;
   for(int i = a;i <= b;i++){
        if(arr[i] == k){
            cnt++;
        }
   }
   cout << cnt << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    sieve();
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



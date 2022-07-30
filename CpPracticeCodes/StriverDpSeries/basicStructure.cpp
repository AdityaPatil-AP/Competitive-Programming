#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverDpSeries\\input.txt","r", stdin);
    freopen("E:\\only one folder\\Cp Codes 1\\CpPracticeCodesGithubRepo\\CpPractice\\StriverDpSeries\\output.txt", "w", stdout);
    #endif

    int n = 10;
    bool *arr = new bool[n + 1]();
    for(int i = 0;i < n;i++){
        cout << arr[i] << endl;
    }
    
    arr[1] = true;
    cout << arr[1] << endl;

    return 0;
}
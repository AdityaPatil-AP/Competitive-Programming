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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n + 1];
        arr[0] = 1;
        for(int i = 1;i <= n;i++){
            if(i % 2 == 0){
                arr[i] = i - 1;
            } 
            else{
                arr[i] = i + 1;
            }
        }
        if(n % 2 != 0){
            arr[n] = arr[n - 1];
            arr[n - 1] = n;
        }
        for(int i = 1;i <= n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
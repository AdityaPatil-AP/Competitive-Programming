#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // MY Attempt
    // int hourS, minS;
    // int n;
    // cin >> n >> hourS >> minS;
    // int minH = INT_MAX, minM = INT_MAX;
    // int minI, hourI, currM, currH;
    // for(int i = 1;i <= n;i++){
    //     cin >> hourI >> minI;
    //     if(hourI >= hourS){
    //         if(minI >= minS && hourI >= hourS){
    //             currM = minI - minS;
    //             currH = hourI - hourS;
    //         }
    //         else if(hourI == hourS && minI < minS){
    //             currM = minS - minI;
    //             currH = 24 - (hourS - hourI) - 1;
    //         }
    //         else{
    //             currM = 60 - (minS - minI);
    //             currH = hourI - hourS - 1;
    //         }
    //     }
    //     else{
    //         if(minI >= minS){
    //             currM = minI - minS;
    //             currH = 24 - (hourS - hourI);
    //         }
    //         else{
    //             currM = 60 - (minS - minI);
    //             currH = 24 - (hourS - hourI) - 1;

    //         }
    //     }
    //     if(currH < minH || (currH == minH && currM <= minM)){
    //         minH = currH;
    //         minM = currM;
    //     }
    // }
    // cout << minH << " " << minM << endl;

    // Editor's Solution and my try
    int n, hs, ms;
    cin >> n >> hs >> ms;
    int minimumMinutes = 24 * 60;
    int sleepTime = (60 * hs) + ms;
    for(int i = 0;i < n;i++){
        int h, m;
        cin >> h >> m;
        int alarmTime = 60 * h + m;
        int timeSlept = alarmTime - sleepTime;
        if(timeSlept < 0) timeSlept += (24 * 60);
        minimumMinutes = min(minimumMinutes, timeSlept);
    }
    cout << minimumMinutes/60 << " " << minimumMinutes%60 << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}
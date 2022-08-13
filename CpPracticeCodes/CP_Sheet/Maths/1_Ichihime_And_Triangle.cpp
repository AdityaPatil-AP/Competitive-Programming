#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // My Attempt - correct
    // int a, b, c, d;
    // cin >> a >> b >> c >> d;
    // bool flag = false;
    // for(int x = a;x <= b;x++){
    //     for(int y = c;y >= b;y--){
    //         for(int z = c;z <= d;z++){
    //             if((x + y) > z && (x + z) > y && (y + z) > x){
    //                 cout << x << " " << y << " " << z << endl;
    //                 flag = true;
    //                 break;
    //             }
    //         }
    //         if(flag == true){
    //             break;
    //         }
    //     }
    //     if(flag == true) break;
    // }

    // Tutorial
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c << " " << c << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet\\output.txt", "w", stdout);
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



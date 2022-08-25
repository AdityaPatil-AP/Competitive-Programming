#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void work(){
    // My bullshit try
    // int n;
    // cin >> n;
    // int start = 1;
    // int end = n * (n + 1);
    // int start1 = 0;
    // int end1 = 4 * n - 2;
    // int temp = n;
    // vector<vector<string>> ans(n, vector<string>(4 * n - 1, " "));
    // for(int i = 0;i < temp;i++){
    //     int cnt = 0;
    //     for(int j = start1;cnt < n;){
    //         string a = to_string(start);
    //         ans[i][j] = a;
    //         start++;
    //         cnt++;
    //         j += 2;
    //     }
    //     cnt = 0;
    //     for(int j = end1;cnt < n;){
    //         string a = to_string(end);
    //         ans[i][j] = a;
    //         end--;
    //         cnt++;
    //         j-=2;
    //     }
    //     cnt = 0;
    //     for(int j = start1 + 1;cnt < 2 * n - 1;){
    //         ans[i][j] = "*";
    //         cnt++;
    //         j+=2;
    //     }
    //     n--;
    //     start1 += 2;
    //     end1 -= 2;
    // }
    // // cout << "Hello" << endl;
    // for(int i = 0;i < temp;i++){
    //     for(int j = 0;j < 4 * temp - 1;j++){
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }

    // MY 2nd attempt
    int i, j, n;
    // cout << "Enter the number for pattern" << endl;
    cin >> n;
    int num1 = 1, num2 = (n * (n + 1)) - (n - 1);
    // cout << num2 << endl;
    for(int i = 1;i <= n;i++){
        int temp = num2;
        for(int j = 1;j <= (4 * n) - 1;j++){
            if(j <=  (2 * n - 1) && j % 2 == 1 && j >= 2 * (i - 1)){
                cout << to_string(num1);
                num1++;
            } 
            else if(j >= (2 * n + 1) && j % 2 == 1 && j < (4 * n - (i * 2 - 2))){
                cout << to_string(temp);
                temp++;
            }
            else if(j <= (i * 2 - 2) || j >= (4 * n - (i * 2 - 2))){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        num2 -= (n - i);
        cout << endl;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



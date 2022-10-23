#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

void work(){
    // My Try
    // Sums In A Cuboid.
    int x, y, z;
    cin >> x >> y >> z;
    // 3 - D vector.
    vector<vector<vector<int>>> sums(x, vector<vector<int>>(y, vector<int> (z, 0)));
    vector<vector<vector<int>>> ans(x, vector<vector<int>>(y, vector<int>(z, 0)));
    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++){
            for(int k = 0;k < z;k++){
                cin >> sums[i][j][k];
            }
        }
    }
    // Creating the Ans Array...
    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++){
            for(int k = 0;k < z;k++){
                int num = sums[i][j][k];
                if(k > 0){
                    num -= sums[i][j][k - 1];
                }
                if(j > 0){
                    num -= sums[i][j - 1][k];
                }
                if(j > 0 && k > 0){
                    num += sums[i][j - 1][k - 1];
                }
                for(int m = 0;m < i;m++){
                    num -= ans[m][j][k];
                }
                ans[i][j][k] = num;
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return; 
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



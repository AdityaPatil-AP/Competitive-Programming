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
int k;
// bool comp(int a, int b){
//     if(a%k == b%k){
//         return true;
//     }
//     return false;
// }

void work(){
    // My Try :
    int n, x, y;
    cin >> n >> x >> y;
    if(x == 0 && y == 0){
        cout << "-1" << endl;
        return;
    }
    if(x == 0 || y == 0){
        if(x == 0){
            if(n % y == 1 || (n == 2 && y== 1) ){
                int temp = 2;
                int count = 0;
                for(int i = 1;i < n;i++){
                    if(count < y){
                        cout << temp << " ";
                        count++;
                    }
                    else{
                        temp += (y);
                        count = 1;
                        cout << temp << " ";
                    }

                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
        else{
            if(n % x == 1 || (n == 2 && y== 1)){
                int temp = 2;
                int count = 0;
                for(int i = 1;i < n;i++){
                    if(count < x){
                        cout << temp << " ";
                        count++;
                    }
                    else{
                        temp += (x);
                        count = 1;
                        cout << temp << " ";
                    }
                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
    }
    else{
        cout << "-1" << endl;
    }
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



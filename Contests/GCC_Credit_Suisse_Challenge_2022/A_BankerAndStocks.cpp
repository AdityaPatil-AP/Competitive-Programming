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

// odd divisor and even divisors.
vector<int> oddDivisors;
vector<int> evenDivisors;

// void divisors(long long int n, int &odd, int &even){
//     if(n % 2 == 0){
//         evenDivisors.push_back(2);
//         if((n/2) % 2 == 0){
//             even++;
//         }
//         else odd++;
//     }
//     // cout << oddDivisors.size() << " " << evenDivisors.size() << endl;
//     for(int i = 3;i * i <= n;i+=2){
//         if(n % i == 0){
//             if(i % 2 == 0){
//                 even++;
//             }
//             else odd++;
//             if((n/i) % 2 == 0){
//                 even++;
//             }
//             else{
//                 odd++;
//             }
//         }
//     }
//     return;
// }

void work(){
    // My Try :
    long long int n;
    cin >> n;
    int odd = 0;
    int even = 0;
    divisors(n, odd, even);
    int oD = oddDivisors.size();
    int eD = evenDivisors.size();
    cout << oD << " " << eD << endl;
    if(oD > eD){
        cout << "SELL" << endl;
    }
    else if(eD > oD) cout << "BUY" << endl;
    else cout << "PASS" << endl;
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
    // cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



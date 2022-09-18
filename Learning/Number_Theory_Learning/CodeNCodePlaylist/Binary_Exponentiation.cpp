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

const int N = 10000005;
#define pb push_back

int binaryExpo(int base, int power, int p){
    int res = 1;
    while(power){
        if(power % 2){
            res = (1ll * res * base)%p, power--;
        }
        else{
            base = (1ll * base * base)%p, power /= 2;
        }
    }
    return res;
}

int binaryExpoRecursive(int base, int power, int p){
    if(power == 0) return 1;
    if(power % 2 == 1){
        int smallAns = binaryExpoRecursive(base, power/2, p);
        return (1ll * smallAns * smallAns * base)%p;
    }
    else{
        int smallAns = binaryExpoRecursive(base, power/2, p);
        return (1ll * smallAns * smallAns) % p;
    }
}

void work(){
    // Binary Exponentiation - 
    cout << binaryExpo(2, 200, mod) << endl;

    cout << binaryExpoRecursive(2, 200, mod) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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



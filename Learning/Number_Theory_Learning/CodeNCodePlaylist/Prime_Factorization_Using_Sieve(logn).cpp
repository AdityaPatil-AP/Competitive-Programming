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

const int maxN = 1000001;
ll arr[maxN] = {0};
// Pre - Computation is Done is O(sqrt(n))
void sieve(){
    // Initialise all the elements as -1, indicating they are unmarked till now
    for(int i = 1;i <= maxN;i++) arr[i] = -1;
    // Starting from 2 till maxN whenever we encounter the unmarked values, 
    // Replace them with the index value, and also all the multiples of it with the same/
    // the same index value.

    for(ll i = 2;i * i <= maxN;i++){
        if(arr[i] == -1){
            arr[i] = i;
            for(ll j = i * i;j <= maxN;j += i){
                if(arr[j] == -1)
                    arr[j] = i;
            }
        }
    }
    return;
}

void primeFact(int n){
    cout << "Prime Factorisation of " << n << " is " << endl;
    while(n > 1){
        if(arr[n] == -1){
            cout << n << endl;
        }
        else cout << arr[n] << " ";
        n /= arr[n]; 
    }
    return;
}

void work(){
    // Prime Factorisation Using Sieve in log(n): 
    primeFact(48);
    cout << endl;
}

int main(){
    sieve();
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



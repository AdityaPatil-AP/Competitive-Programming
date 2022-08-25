#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define int long long int

const int N = 1000000;
#define pb push_back

#define SIEVE
int primes[N];
vector<int> pr;
void sieve(){
    for(int i = 2;i <= N;i++){
        if(primes[i] == 0){
            pr.pb(i);
            for(int j = i * i;j <= N;j+=i){
                primes[j] = 1;
            }
        }
        primes[i] ^= 1;
    }
}

// O(n) time complexity
int divisors(int n){
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(n % i == 0) cnt++;
    }
    return cnt;
}

// O(sqrt(n)) time complexity
int divisors1(int n){
    int cnt = 0;
    for(int i = 1; i * i <= n;i++){
        if(n % i == 0){
            if(i * i != n)
                cnt += 2; // i and (n / i) are factors
            else cnt+=1;
        }
    }
    return cnt;
}

// For finding Prime Numbers in a faster way.
// Time Complexity : O(nlog(log(n))); -> very fast almost linear
void sieve(int n){
    vector<int> prime(n + 1, 1);
    prime[1] = 0;
    for(int i = 2;i <= n;i++){
        if(prime[i] == 1){
            // 2i, 3i, 4i, 
            for(int j = i * i;j <= n;j += i){
                prime[j] = 0;
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(prime[i] == 1) cnt++;
    }
    cout << cnt << endl;
}

// GCD of two numbers using Euclidean Algorithm
// Time Complexity : O(log(min(a, b)));
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

// Power Function
// Binary Exponentiation or binpow
// Time complexity - O(log(b)).
int power(int a, int b, int m){
    if(b == 0){
        return 1;
    }
    if(b%2 == 0) return 1ll * (power(a,b/2,m)%m * power(a, b/2,m)%m)%m;
    return 1ll * (a%m * (power(a, b/2, m)%m * power(a, b/2,m)%m)%m);
}

  
void work(){
    // Utkarsh Gupta Number Theory Video
    // 1st Part - 1) Counting divisors
    int n;cin >> n;
    cout << divisors(n) << endl;
    cout << divisors1(n) << endl;

    // Printing divisors for all numbers from 1 to n.
    // Using a vector and use of multiples
    // vector<int> div(n + 1);
    // for(int i = 1;i <= n;i++){
    //     for(int j = i;j <= n;j+=i ){
    //         div[j]++;// i is a divisor of j.
    //     } 
    // }
    // for(int i = 1;i <= n;i++){
    //     cout << div[i] << " ";
    // }
    // cout << endl;

    // For finding primes numbers in a range we can use
    // Sieve of Eratosthenes
    sieve(n);

    // GCD of two numbers
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    // In-built function
    cout << __gcd(a, b) << endl;

    // 2nd Part - Modular Arithmetic.
    // Power function
    int m, p, j;
    cin >> m >> p >> j;
    // Binary Exponentiation or Binpow
    cout << power(m, p, j) << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    auto start = high_resolution_clock::now();
    for(int i = 0;i < testcase;i++){
        work();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}



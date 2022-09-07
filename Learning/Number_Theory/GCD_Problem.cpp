#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

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

// Fermat's little theorem
int multiplicativeInverse(int b, int modm){
    return power(b, modm - 2, modm); // Fermat's little theorem
}
  
// Factorial and Inverse Factorial in Combinatorics
int fact[N], invfact[N];
void init(){
    int p = PRIME;
    fact[0] = 1;
    int i;
    for(i = 1;i < N;i++){
        fact[i] = i * fact[i - 1];
    }
    i--;
    invfact[i] = power(fact[i], p - 2, p);
    for(i--;i >= 0;i--){
        invfact[i] = invfact[i + 1] * (i + 1) % p;
    }
}
int ncr(int n, int r){
    if(r > n || n < 0 || r < 0){
        return 0;
    }
    return fact[n]%PRIME * invfact[r]%PRIME * invfact[n - r]%PRIME;
}

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5;i * i <= n;i = i + 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}


void work(){
    // Editorial Answer 1 - Constructive Method 
    // int n;
    // cin >> n;
    // if(n % 2 == 0){
    //     cout << n - 3 << " " << 2 << " " << 1 << endl;
    // }
    // else if(n % 4 == 1){
    //     cout << n/2 - 1 << " " << n/2 + 1 << " " << 1 << endl;
    // }
    // else{
    //     cout << n/2 - 2 << " " << n/2 + 2 << " " << 1 << endl;
    // }

    // Editorial Answer 2 - Brute Force
    int n;
    cin >> n;
    for(int a = 2; true;a++){
        if(gcd(a, n - a - 1) != 1 || a == n - a - 1) continue;
        cout << a << " " << n - a - 1 << " " << 1 << endl;
        break;
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
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



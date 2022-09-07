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

unsigned int simpleMethodSetBits(unsigned int x){
    int count = 0;
    while(x){
        count += x & 1;
        x >>= 1;
    }
    return count;
}

unsigned int BrianKernighanSetBitsRecursive(unsigned int x){
    if(x == 0) return 0;
    return 1 + BrianKernighanSetBitsRecursive(x & (x - 1));
}

unsigned int BrianKernighanSetBits(unsigned int x){
    int count = 0;
    while(x){
        count++;
        x = x & (x - 1);
    }
    return count;
}

unsigned int checkPower2(unsigned int x){
    return (x && !(x & (x - 1)));
}

unsigned int logbase2(int x){
    int res = 0;
    while(x){
        res++;
        x >>= 1;
    }
    return res;
}

unsigned int lastSetBit(unsigned int x){
    return log2(x & -x) + 1;
}

int setBit(int num, int pos){
    return (num | (1 << pos));
}

int unsetbit(int num, int pos){
    return (~(1 << pos) & num);
}

int toggleBit(int num, int pos){
    return num = num ^ (1 << pos);
}

bool checkSetUnset(int num, int pos){
    bool bit = (1 << pos) & num;
    return bit;
}

int onesComplement(int num){
    return ~num;
}

int twosComplement(int num){
    return ~num + 1;
}

void strip_last_bit(int &num){
    num = num & (num - 1);
    return;
}

int lowest_set_bit(int num){
    int ans = num & (-num);
    return ans;
}

void work(){
    
    // Bitwise Hacks For Competitive Programming.

    // 1) Setting n'th bit.
    int n = 4, pos = 1;
    cout << setBit(4, 1) << endl;

    // 2) How to clear a bit at n'th position.
    n = 7, pos = 1;
    cout << unsetbit(n, pos) << endl;

    // 3) Toggling the bit - Use "Xor" Operator
    n = 4, pos = 1;
    cout << toggleBit(n, pos) << endl;

    // 4) Checking it the bit at n'th position is set or unset
    n = 5, pos = 1;
    cout << checkSetUnset(n, pos) << endl; 

    // 5) 1's Complement and 2's Complement.
    int num = 4;
    cout << onesComplement(num) << endl;
    cout << twosComplement(num) << endl;

    // 6) Stripping last bit.
    num = 14;
    strip_last_bit(num);
    cout << num << endl;

    // 7) Getting lowest bit
    num = 24;
    int ans = lowest_set_bit(num);
    cout << ans << endl;

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




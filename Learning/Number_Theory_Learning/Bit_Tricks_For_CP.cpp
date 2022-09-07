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

void work(){
    
    // Facts of this article
    // 1. 0 - based indexing of bits from left to right
    // 2. Setting i-th bit means turning i-th bit to 1
    // 3. Clearing i-th bit means turning i-th bit to 0

    // 1. Clearing all bits from LSB to i.
    // This means that we have to make a mask where all bits from 
    // LSB to i are 0 and remaining are 1.

    // mask = ~((1 << (i + 1)) - 1)
    // x &= mask;

    int x = 29;
    int i = 3;
    int mask = (1 << (i + 1));
    mask = mask - 1;
    mask = ~mask;
    x &= mask;
    cout << x << endl;

    // 2. Clearing all bits from MSB to i-th bit.
    // here all the from MSB to i-th bit should be zero.
    // mask = (1 << i) - 1;

    x = 215;
    i = 4;
    mask = (1 << i) - 1;
    x &= mask;
    cout << x << endl;

    // Divide by 2;
    // x >>= 1;
    x = 18;
    x >>= 1;
    cout << x << endl;

    // Multiply by 2;
    // x <<= 1;
    x = 18;
    x <<= 1;
    cout << x << endl;

    // 5. Upper Case to Lower Case
    // A = 65 to a = 97;
    // a - A = 32
    // 32 ascii value is of ' ' character.
    // The difference is the 5 bit of  'A' which should be set.
    // For setting we have to mask it .with 0010 0000 which is 
    // actually white space character (' ')
    char ch = 'A';
    ch |= ' ';
    cout << ch << endl;

    // 6. Lower Case to Upper Case
    // to convert the lower case to upper case we have to convert
    // the 5th bit of the lower case character to 0.
    // So we have to AND 1101 1111 with the lower case character.
    // mask = '_'; 1101 1111
    ch = 'a';
    ch &= '_';
    cout << ch << endl;

    // 7. Count the No. of set bits.
    x = 255;
    cout << simpleMethodSetBits(x) << endl;
    cout << BrianKernighanSetBits(x) << endl;
    cout << BrianKernighanSetBitsRecursive(x) << endl;

    // 8. Find log base 2 of a 32-bit integer.
    x = 255;
    cout << logbase2(x) << endl;

    // 9. Check if 32 - bit integer is a power of 2.
    x = 33;
    cout << checkPower2(x) << endl;

    // 10. Find the last bit
    x = 6;
    cout << lastSetBit(x) << endl;
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




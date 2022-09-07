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

int computeXor(int n){
    // Naive Approach
    // int ans = 0;
    // for(int i = 1;i <= n;i++){
    //     ans ^= i;
    // }
    // return ans;
    // Time Complexity - O(n);

    // Efficient Approach - Based on Observation
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}

int countUnsetBitsThenCondition(int n){
    int count = 0;
    while(n){
        if((n & 1) == 0) count++;
        n >>= 1;
    }
    return 1 << count;
}

bool isPowerOf2(int x){
    return (x && !(x & (x - 1)));
}

bool xorAllSubsets(int arr[], int x){
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int n1 = *(&arr + 1) - arr;
    // cout << n1 << endl;
    if(x == 1) return arr[0];
    return 0;
}

void swap1(int &m , int &n){
    if(m == n){
        return;
    }
    m = m ^ n;
    n = n ^ m;
    m = m ^ n;
    return;
}

void work(){
    // 1) compute xor from 1 to n.
    // For this we can use naive approach which would take O(n) time.
    // Or else the efficient approach would be to use some generalization 
    // after analysing some Test cases. This reduces the time complexity to
    // O(1) time complexity.

    int n = 16;
    cout << computeXor(n) << endl;

    // 2) Count number of x which are smaller than such that
    //     (n + x) == (n ^ x).
    //  We know that (n + x) = (n ^ x) + n & x;
    // for the condition to be true n & x must be zero.

    // Therefore to find out the number, let's do the observation,
    // if the k-th set bit of n is there, then the bit of x must be unset, 
    // So that n & x be 0. At the un-set bit of n, the bit of x can be 0 or 1.
    // The possible combinations will be the 2 to power of count of unset bits
    // in n.

    n = 16;
    cout << countUnsetBitsThenCondition(n) << endl;

    // 3) Is Power of 2
    // 
    n = 31;
    cout << isPowerOf2(n) << endl;

    // 4) Xor of all the subsets of the set.
    int arr[] = {6};
    n = sizeof(arr)/sizeof(arr[0]);
//     &arr – Pointer to an array of 6 elements. [See this for difference between &arr and arr]
// (&arr + 1) – Address of 6 integers ahead as pointer type is a pointer to an array of 6 integers. In simple words, (&arr + 1) is the address of integers ahead.
// *(&arr + 1) – Same address as (&arr + 1), but type of pointer is “int *”.
// *(&arr + 1) – arr – Since *(&arr + 1) points to the address 6 integers ahead of arr, the difference between two is 6.
    // Basically, “array” is a “pointer to the first element of array” 
    // but “&array” is a “pointer to whole array of 5 int”. 
    n = *(&arr + 1) - arr;
    cout << xorAllSubsets(arr,n) << endl;

    // 5) Some Gcc compiler inbuilt functions.
    // n = 9 (0000 1001)
    // __builtin_popcount(x) - returns the set bits.
    n = 9;
    cout << __builtin_popcount(n) << endl;
    // __builtin_parity(x) - returns if the number is of odd
    // or even parity. 
    // If it returns 1 - odd parity. which means odd number of 1's
    // If it returns 0 - even parity. which means even number of 1's
    n = 8;
    cout << __builtin_parity(n) << endl;

    // __builtin_clz(x) and __builtin_ctz(x) to clear leading and 
    // trailing zeroes.
    n = 16;
    cout << __builtin_clzll(n) << endl;
    cout << __builtin_ctzll(n) << endl; 

    // 6. Convert a Binary Code directly to an Integer.
    // '0b' is used to tell the computer that the number you 
    // typed is a base-2 number not a base-10 number.
    int a = 0b1011;
    cout << a << endl; 

    // 7. Quickest Way to swap two numbers.
    // Using Xor Operator.
    // 
    int m = 10, n2 = 5;
    cout << (m ^ n2) << endl;

    // 8. Swap using bitwise xor Bitwise Xor
    // Using xor operator 
    m = 10;
    n = 5;
    cout << m << " " << n << endl;
    swap1(m, n);
    cout << m << " " << n << endl;

    // 8. and 9. To be  done 
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




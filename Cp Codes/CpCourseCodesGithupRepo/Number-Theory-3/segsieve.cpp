#include <bits/stdc++.h>
using namespace std;
#define MAX 100001 

vector<int>* sieve(){
    bool isPrime[MAX];
    for(int i = 0; i < MAX;i++){
        isPrime[i] = true;
    }
    for(int i = 2;i * i < MAX;i++){
        if(isPrime[i]){
            for(int j = i * i;j < MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i = 3; i < MAX;i+=2){
        if(isPrime[i]){
            primes->push_back(i);
        }
    }
    return primes;
}

void printPrimes(long long int l, long long int r, vector<int>* &primes){
    bool isPrime[r - l + 1];
    for(int i = 0; i <= r - l;i++){ 
        isPrime[i] = true;
    }

    for(int i = 0;(long long)primes->at(i) * (long long)primes->at(i) <= r;i++){
        int currPrime = primes->at(i);
        // Just smaller or equal to value to l.
         long long base = (l/(currPrime))*(currPrime);
         if(base < l){
             base = base + currPrime;
         }
         // Mark all multiples within L to R as false.
         for(long long j = base;j <= r;j+=currPrime){
             isPrime[j - l] = false;
         }
         // if base becomes zero. 
         // There may be a case where base itself a prime number.
         if(base == currPrime){
             isPrime[base - l] = true;
         }
    }
    if(l == 1){
        isPrime[0] = false;
    }

    for(int i = 0; i <= r - l;i++){
        if(isPrime[i]){
            cout << i + l << endl;
        }
    }
}

int main(){
    vector<int>* primes = sieve();
    int t;
    cin>>t;
    while(t--){
        long long int l, r;
        cin >> l >> r;
        printPrimes(l, r, primes);
    }

    return 0;
}
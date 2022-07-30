#include <iostream>
using namespace std;
// my effort
int noOfPrimes(int n){
    bool *isPrime = new bool[n + 1];
    for(int i = 0;i <= n;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2;(i * i) <= n;i++){
        if(isPrime[i] == true){
            for(int j = i * i;j <= n;j += i){
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 0;i <= n;i++){
        if(isPrime[i]){
            count++;
        }
    }
    return count;
}

int makeSieve(int n){
    bool *isPrime = new bool[n + 1];
    for(int i = 0; i <= n;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2;(i * i) <= n;i++){
        if(isPrime[i] == true){
            for(int j = i * i;j <= n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    // Just to view the sieve.
    // for(int i = 0;i <= n;i++){
    //     cout << i << " : " << isPrime[i] << endl;
    // }
    int count = 0;
    for(int i = 0;i <= n;i++){
        if(isPrime[i] == true){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    // My part..
    // cout << noOfPrimes(n) << endl;
    // Sir
    int nPrimes = makeSieve(n);
    cout << nPrimes << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define PRIME 1000000007
#define MOD 1000000007

int power(int a, int b, int m){
    if(b == 0){
        return 1;
    }
    if(b%2 == 0) return 1ll * (power(a,b/2,m)%m * power(a, b/2,m)%m)%m;
    return 1ll * (a%m * (power(a, b/2, m)%m * power(a, b/2,m)%m)%m);
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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
    return 0;
}
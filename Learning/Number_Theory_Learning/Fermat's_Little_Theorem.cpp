#include <bits/stdc++.h>
using namespace std;

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
  

int main(){
	#ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
    #endif
	return 0;
}
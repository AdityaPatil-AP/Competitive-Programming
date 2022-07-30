#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Triplet{
    public:
    ll gcd;
    ll x;
    ll y;
};

Triplet gcdExtendedEuclid(ll a, ll b){
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet smallAns = gcdExtendedEuclid(b, a%b);
    // Extended Euclid says
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x -(a/b)*smallAns.y;
    return ans;
}

ll modInverse(ll A, ll M){
    ll x = gcdExtendedEuclid(A, M).x;
    return (x % M + M)%M;
}

int main(){
    
    return 0;
}  
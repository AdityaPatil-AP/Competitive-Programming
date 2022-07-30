#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define ll long long int

int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.length();i++){
        int m = a[i] - '0';
        int mI = 9 - (a[i] - '0');
        if(i == 0 && mI == 0){
            // char mR = m;
            a[i] = m + '0';
        }
        else{
            int minimum = min(m, mI);
            // char mR = minimum;
            a[i] = minimum + '0';
        }
    }
    ll ans = 0;
    for(int i = 0;i < a.length();i++){
        ans = (ans * 10) + (a[i] - '0');
    }
    cout << ans;
    // int a = 1;
    // char m = a ;
    // cout << m << endl;
    // return 0;
}

// Data
// https://www.delftstack.com/howto/cpp/how-to-convert-int-to-char-array-in-cpp/

// char + int = int;
// char m = 48;
// then m will store '0' in it.
// if char m = 33; 
// then some another ascii code will stored in it.
// one of the good solutions
// #include <bits/stdc++.h>
// using namespace std;
//  typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// #define mp make_pair
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif
// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}
// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
//  void aman(){
// ll n;
//  cin>>n;
//  vector<ll>v;
//  while(n!=0){
//      ll a=n%10;
//      v.push_back(a);
//      n=n/10;
//  }
// //  debug(v)
//  reverse(v.begin(),v.end());
//  if(v[0]>4 and v[0]<9){v[0]=9-v[0];cout<<v[0];}
//  else cout<<v[0];
//  for (ll i = 1; i < v.size(); i++)
//  {
    
 
//      if(v[i]>4  ){v[i]=9-v[i];}
//      cout<<v[i];
//  }
// cout<<endl;
 
//  }
 
// int main(){
//  ios::sync_with_stdio(false);
// cout.tie(0); cin.tie(0);
//  ll t=1;
// //  cin>> t;
//  while(t--){
//  aman();
//  }
 
// return 0;
// }
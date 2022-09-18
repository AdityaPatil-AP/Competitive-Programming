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

#define double long double

double c;

bool good(double m){
    double val = pow(m,2) + sqrt(m);
    return (val <= c);
}

void work(){
    // Equation
    
    cin >> c;
    double l = sqrt(c/2), r = sqrt(c);
    cout << setprecision(20);
    for(int i = 0;i < 100;i++){
        double mid = (l + r)/2;
        if(good(r)){
            r = mid;
        }
        else l = mid;
    }
    cout << r << endl;
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



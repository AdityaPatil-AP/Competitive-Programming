#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

vector<int> primes;
bool prime[n + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            primes.pb(p);
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


void work(){
    // My Try :
    int n;
    cin >> n;
    set<int> st;
    vector<int> arr;
    for(int i = 0;i < n;i++){
        int input;
        cin >> input;
        st.insert(input);
        arr.push_back(input);
    }
    int k;
    cin >> k;
    for(int i = 0;i < k;i++){
        int input;
        cin >> input;
        auto it = st.find(input);
        st.erase(it);
    }
    // stack<int> stm;
    // for(auto it : st){
    //     stm.push(it);
    // }
    // while(!stm.empty()){
    //     cout << stm.top() << " ";
    //     stm.pop();
    // }
    for(int i = 0;i < n;i++){
        if(st.find(arr[i]) != st.end()){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



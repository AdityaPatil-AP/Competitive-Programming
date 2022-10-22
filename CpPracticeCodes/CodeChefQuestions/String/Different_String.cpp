#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

#define ll long long int

void work(){
    // My Try
    // Different String.
    ll n;
    cin >> n;
    set<string> st;
    // We are given a set of n strings.
    // We will store them in a container.
    // Possible Configurations that we can make are 2^n for a 
    // binary string of length n.
    // Here we have just got n strings out of them.
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        st.insert(s);
    }
    // Possible what we can do is create a string with all zeroes
    // or all ones and change their configurations as we go.  
    string a = "";
    // added later
    string b = "";
    for(int i = 0;i < n;i++){
        a.push_back('0');
        b.push_back('1');
    }
    // There are only n strings given even if we check the intial string at
    // each iteration and by changing 0 to 1. 
    // There are (n + 1)strings generated which are enough for these 
    // constraints.
    // Or else what you can do is take two strings a and b
    // where a is initialised with all zeroes and b is initialised with
    // all ones.
    // In that case I will have 2 * n different strings.
    if(st.find(a) == st.end()) cout << a << endl;
    else{
        for(int i = 0;i < n;i++){
            a[i] = '1';
            b[i] = '0';
            if(st.find(a) == st.end()){
                cout << a << endl;
                break;
            }
            // added later
            else if(st.find(b) == st.end()){
                cout << b << endl;
                break;
            }
        }
    }
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    fast_io
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}



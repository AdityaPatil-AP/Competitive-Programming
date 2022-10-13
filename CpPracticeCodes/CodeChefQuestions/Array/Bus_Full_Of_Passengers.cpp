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
    // Bus Full of Passengers. - Done
    // int n, m, q;
    // cin >> n >> m >> q;
    // // Set will store the persons present in the bus.
    // set<int> st;
    // bool flag = true;
    // int size = 0;
    // while(q--){
    // 	char j;
    // 	int i;
    // 	cin >> j;
    // 	cin >> i;
    // 	if(j == '+'){
    // 		if((size + 1) > m){
    // 			flag = false;
    // 		}
    // 		st.insert(i);
    // 		size++;
    // 	}
    // 	else if(j == '-'){
    // 		if(st.find(i) == st.end()){
    // 			flag = false;
    // 		}
    // 		size--;
    // 	}
    // }
    // (flag) ? cout << "Consistent" : cout << "Inconsistent";
    // cout << endl;

    int n, m, q;
    cin>>n>>m>>q;
    int count = 0, pid;
    char c;
    bool flag = true;
    unordered_map<int, int> um;
    while(q--)
    {
        cin>>c>>pid;

        if(c == '+') 
        {
            um[pid]++;
            m--;
        }
        else 
        {
            um[pid]--;
            m++;
        }

        if(m < 0) flag = false;
    }

    if(flag) cout<<"Consistent";
    else cout<<"Inconsistent";
    cout << endl;
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



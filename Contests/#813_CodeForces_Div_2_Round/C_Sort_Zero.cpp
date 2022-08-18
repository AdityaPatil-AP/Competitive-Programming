#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define len(t) (int)t.size()
#define forn(i, n) for(int i = 0;i < int(n);i++)

void work(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    while(true){
        int minimum = *min_element(arr.begin(), arr.end());
        int mini;
        for(int i = n - 1;i >= 0;i--){
            if(arr[i] == minimum){
                mini = i;
                break;
            }
        }
        set<int> st;
        bool minInclude = false;
        for(int i = 0;i < mini;i++){
            if(arr[mini] == arr[i])
                minInclude = true;
            st.insert(arr[i]);
        }
        if(minInclude == true){
            for(int i = 0;i <= mini;i++){
                arr[i] = 0;
            }
        }
        else{
            for(int i = mini + 1;i < n;i++){
                if(st.find(arr[i]) != st.end()){
                    for(int j = mini; j <= i;j++){
                        arr[j] = 0;
                        continue;
                    }
                }
            }
            break;
        }
    }

}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}
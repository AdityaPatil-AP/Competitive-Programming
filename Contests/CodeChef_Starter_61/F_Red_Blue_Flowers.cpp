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

int f(int index, vector<int> &arr1, vector<int> &arr2){
	// Base Case
	if(index == n){
		return 0;
	}
	// Choosing the red Flower
	int ans1 = arr1[index] + f(index + 1, arr1, arr2);
	// Choosing the blue flower
	int ans2 = arr2[index] + f(index + 1, arr1, arr2);
	return min(ans1, ans2);
}

void work(){
    // My Try :
    // F) Red Blue Flowers
    int n;
    cin >> n;
    vector<int> arr1(n, 0);
    vector<int> arr2(n, 0);
    for(int i = 0;i < n;i++){
    	cin >> arr1[i];
    }
    for(int i = 0;i < n;i++){
    	cin >> arr2[i];
    }
    // int ans1 = 0, ans2 = 0;
    int ans = f(0, arr1, arr2);
    cout << ans << endl;
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



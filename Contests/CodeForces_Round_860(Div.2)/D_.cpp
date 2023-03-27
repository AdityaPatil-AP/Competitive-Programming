#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Macros list.


#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

// GitHub Repository for Large Code Implementations.


// After solving the problem, look for solution of higher rated person.
// Understand what optimisation he has done.

// Prove your problem correctness. Why only this work here?

// See the constraints, and solve it, don't over optimise.

// Always read the editorial for an unsolved problem.

// You are almost there, Don't stop now. Great Thing takes time.
// If you think, there is another idea that may work, go for it as well!!

void work(){
    // My Try :
    // A) 

	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(auto &x : arr) cin >> x;

    ll diff = *(max_element(arr.begin(), arr.end())) - *(min_element(arr.begin(), arr.end()));

	priority_queue<ll> pq1;
	priority_queue<ll, vector<ll>, greater<ll>> pq2;

	for(int i = 0;i < arr.size();i++){
		if(arr[i] >= 0){
			pq1.push(arr[i]);
		}
		else{
			pq2.push(arr[i]);
		}
	}


	ll currsum = 0;
	vector<ll> ans;
	for(int i = 0;i < n;i++){
		if(!pq1.empty() && (currsum + pq1.top() < diff)){
			ans.push_back(pq1.top());
			currsum += pq1.top();
			pq1.pop();
		}
		else if(!pq2.empty()){
			ans.push_back(pq2.top());
			currsum += pq2.top();
			if(currsum < 0){
				currsum = 0;
			}
			pq2.pop();
		}
	}

	if(n != ans.size()){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
		for(int i = 0;i < ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
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



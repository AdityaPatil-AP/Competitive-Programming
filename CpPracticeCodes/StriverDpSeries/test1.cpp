#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool isPossible(int sumX,int index,  int n, int *arr, vector<int>&elements){
	bool ans;
	if(index == n){
		if(sumX == 0){
			return true;
		}
		else{
			return false;
		}
	}
	if(sumX == 0){
		ans = true;
		return ans;
	}
	if(sumX < 0){
		ans =  false;
		return ans;
	}
	bool path1, path2;
	if(sumX - arr[index] >= 0){
		elements.push_back(arr[index]);
		path1 = isPossible(sumX - arr[index], index + 1, n, arr, elements);
		if(path1 == false){
			while(elements.size() != 0){
				elements.pop_back();
			}
		}
	}
	if(path1 == false){
		path2 = isPossible(sumX, index + 1, n, arr, elements);
	}
	if(path1 || path2){
		return true;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    int f = t;
    while(t--){
    	int n, x, y;
    	cin >> n >> x >> y;
    	int sum = 0;
    	int arr[n];
    	for(int i = 1; i <= n;i++){
    		sum += i;
    		arr[i - 1] = i;
    	}
    	int a;
    	if(sum % (x + y) == 0){
    		a = (sum / (x + y));
    	}
    	else{
    		cout << "Case #" << f - t  << ": " << "IMPOSSIBLE" << endl;
    		continue;
    	}
    	int sumX = a * x;
    	vector<int> elements;
    	bool ans = isPossible(sumX, 0,  n, arr, elements);
    	if(ans == true){
			cout << "Case #" << f - t  << ": " << "POSSIBLE" << endl;
			cout << elements.size() << endl;
			for(int i = 0; i < elements.size();i++){
				cout << elements[i] << " ";
			}
			cout << endl;
    	}
    	else{
    		cout << "Case #" << f - t  << ": " << "IMPOSSIBLE" << endl;
    	}

	}
}
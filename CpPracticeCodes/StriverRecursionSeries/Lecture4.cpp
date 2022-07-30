#include<bits/stdc++.h>
using namespace std;

void reverse(int index, int arr[], int n){
	if(index >= n/2){
		return;
	}
	swap(arr[index], arr[n - index - 1]);
	reverse(index + 1, arr, n);
}

bool palindrome(int index, string &s, int n){
	if(index >= n/2){
		return true;
	}
	if(s[index] != s[n - index - 1]){
		return false;
	}
	return palindrome(index + 1, s, n);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	reverse(0, arr, n);
	for(int i = 0;i < n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	string s = "racecar";
	cout << palindrome(0, s, s.size()) << endl;
	cout << endl;
	return 0;
}
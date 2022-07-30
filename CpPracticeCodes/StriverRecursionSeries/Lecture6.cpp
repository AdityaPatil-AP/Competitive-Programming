#include<bits/stdc++.h>
using namespace std;

void printAllSubsequences(int index, int arr[], int n, vector<int> &ans){
	if(index >= n){
		// for(int i = 0;i < ans.size();i++){
		// 	cout << ans[i] << " ";
		// }
		for(auto it : ans){
			cout << it << " ";
		}
		if(ans.size() == 0){
			cout << "{}";
		}
		cout << endl;
		return;
	}

	// don't take the element at current index
	printAllSubsequences(index + 1, arr, n, ans);
	
	// take or pick the particular index into the subsequence
	ans.push_back(arr[index]);
	printAllSubsequences(index + 1, arr, n, ans);
	ans.pop_back();

	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[] = {3, 1, 2, 5};
	vector<int> ans;
	int n = 4;
	printAllSubsequences(0, arr, n, ans);
	return 0;
}
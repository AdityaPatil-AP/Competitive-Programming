#include<bits/stdc++.h>
using namespace std;

// bool flag = false;
// Printing All Subsequences
void printAllSubsequencesSumK(int index, int arr[], int size, vector<int> &v, int currsum, int k){
	if(index == size){
		if(currsum == k){
			// for(int i =0;i < v.size();i++){
			// 	cout << v[i] <<" ";
			// }
			// flag = true;
			for(auto it:v){
				cout << it << " " ;
			}
			cout << endl;
		}
		return;
	}
	// take
	v.push_back(arr[index]);
	currsum += arr[index];
	printAllSubsequencesSumK(index + 1, arr, size, v, currsum, k);
	v.pop_back();
	currsum -= arr[index];
	// Not take
	printAllSubsequencesSumK(index + 1, arr, size, v, currsum, k);
}

// Printing 1 Subsequence
bool printAllSubsequencesSumK1Answer(int index, int arr[], int size, vector<int> &v, int currsum, int k){
	if(index == size){
		// condition satisfied
		if(currsum == k){
			for(auto it:v){
				cout << it << " " ;
			}
			cout << endl;
			return true;
		}
		// condition not satisfied.
		return false;
	}
	// take
	v.push_back(arr[index]);
	currsum += arr[index];
	bool ans = printAllSubsequencesSumK1Answer(index + 1, arr, size, v, currsum, k);
	if(ans == true){
		return true;
	}
	v.pop_back();
	currsum -= arr[index];
	// Not take
	if(printAllSubsequencesSumK1Answer(index + 1, arr, size, v, currsum, k) == true) return true;
	return false;
}

// Counting the Subsequences
int printAllSubsequencesSumKCount(int index, int arr[], int size, int currsum, int k){
	if(index == size){
		// condition satisfied
		if(currsum == k){
			return 1;
		}
		// condition not satisfied.
		return 0;
	}
	// can be done if array contains only positive numbers.
	if(currsum > k){
		return 0;
	}
	// take
	// v.push_back(arr[index]);
	currsum += arr[index];
	int ans1 = printAllSubsequencesSumKCount(index + 1, arr, size, currsum, k);
	// v.pop_back();
	currsum -= arr[index];
	// Not take
	int ans2 = printAllSubsequencesSumKCount(index + 1, arr, size, currsum, k);

	return ans1 + ans2;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[] = {1, 2, 3, 1, 5, 7};
	int k = 10;
	vector<int> print;
	int ans =printAllSubsequencesSumKCount(0, arr, 7, 0, k);
	cout << ans << endl;
	return 0;
}
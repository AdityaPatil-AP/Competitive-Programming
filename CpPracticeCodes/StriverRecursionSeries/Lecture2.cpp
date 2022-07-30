#include <bits/stdc++.h>
using namespace std;

 void printName(int i, int n){
 	if(i > n){
 		return;
 	}
 	cout << "Aditya" << endl;
 	printName(i + 1, n);
 }

 void printNum(int i, int n){
 	if(i > n){
 		return;
 	}
 	cout << i << endl;
 	printNum(i + 1, n);
 }

 void printNumRev(int i, int n){
 	if(i < 1){
 		return;
 	}
 	cout << i << endl;
 	printNumRev(i - 1, n);
 }

 void printNumBT(int i, int n){
 	if(i < 1){
 		return;
 	}
 	printNumBT(i - 1, n);
 	cout << i << endl;
 }

void printNumRevBT(int i, int n){
	if(i > n){
		return;
	}
	printNumRevBT(i + 1, n);
	cout << i << endl;
}


// Backtracking is an algorithmic-technique for solving problems 
// recursively by 
// trying to build a solution incrementally, one piece at a 
// time, removing those solutions that fail to satisfy the
//  constraints of the problem at any point of time 
//  (by time, here, is referred to the time elapsed till reaching
//   any level of the search tree). 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// 1) Print name 5 times
	int n;
	cin >> n;
	printName(1, n);
	cout << endl;
	printNum(1, n);
	cout << endl;
	printNumRev(n, n);
	cout << endl;
	printNumBT(n, n);
	cout << endl;
	printNumRevBT(1, n);
	return 0; 
}
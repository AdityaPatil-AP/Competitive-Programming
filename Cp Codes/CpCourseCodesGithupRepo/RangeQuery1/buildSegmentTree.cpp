#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int value){
	if(start == end){
		arr[index] = value;
		tree[treeNode] = value;
		return;
	}

	int mid = (start + end)/2;
	if(index > mid){
		updateTree(arr, tree, mid + 1, end, 2*treeNode + 1, index, value);
	}else{
		updateTree(arr, tree, start, mid, 2*treeNode, index, value);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right){

	// Completely Outside of given Range
	if(end < left || start > right){
		return 0;
	}

	// Completely inside of given range
	if(start >= left && end <= right){
		return tree[treeNode];
	}

	// Partially inside and partially outside
	int mid = (start + end)/2;
	int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
	int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

	return ans1 + ans2;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("E:\\only one folder\\Cp Codes 1\\Cp Codes\\CpCourseCodesGithupRepo\\Cp\\input.txt", "r", stdin);
	freopen("E:\\only one folder\\Cp Codes 1\\Cp Codes\\CpCourseCodesGithupRepo\\Cp\\output.txt", "w", stdout);
	#endif
	int arr[] = {1, 2, 3, 4, 5};
	int* tree = new int[10];
	buildTree(arr, tree, 0, 4, 1);

	for(int i = 1;i < 10;i++){
		cout << tree[i] << endl;
	}

	updateTree(arr, tree, 0, 4, 1, 2, 10);
	cout << "Updated Segment Tree : " << endl;
	for(int i = 1;i < 10;i++){
		cout << tree[i] << endl;
	}

	int ans = query(tree, 0, 4, 1, 2, 4);
	cout << "\n" << "Sum between interval is : " << ans << endl;
	return 0;
}
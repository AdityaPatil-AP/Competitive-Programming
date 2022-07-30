#include<bits/stdc++.h>
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

void updateTree(int *tree, int start, int end, int treeNode, int index, int value){
	if(start == end){
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end)/2;
	if(index > mid){
		updateTree(tree, mid + 1, end, 2*treeNode + 1, index, value);
	}
	else{
		updateTree(tree, start, mid, 2 * treeNode, index, value);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right){
	// completely outside
	if(start > right || end < left){
		return 0;
	}
	// completely inside
	if(left <= start && right >= end){
		return tree[treeNode];
	}
	// partially inside
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
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	int size = pow(2, ceil(log2(n)) + 1);
	int *tree = new int[size];
	for(int i = 0;i < size;i++){
		tree[i] = 0;
	}

	buildTree(arr, tree, 0, n - 1, 1);
	cout << "Segment Tree : " << endl;
	for(int i = 1;i < size;i++){
		cout << tree[i] << endl;
	}
	updateTree(tree, 0, n - 1, 1, 3, 10);
	cout << "Updated Segment Tree : " << endl;
	for(int i = 1;i < size;i++){
		cout << tree[i] << endl;
	}
	int ans = query(tree, 0, n - 1, 1, 2, 4);
	cout << "Sum between interval is : " << ans << endl;
	return 0;
}
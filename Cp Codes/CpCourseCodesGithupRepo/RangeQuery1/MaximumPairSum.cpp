#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int max;
	int smax;
}node;

void buildTree(int *arr, node * tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode].max = arr[start];
		tree[treeNode].smax = INT_MIN;
		return;
	}

	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	node left = tree[2 * treeNode];
	node right = tree[2 * treeNode + 1];
	tree[treeNode].max = max(left.max, right.max);
	tree[treeNode].smax = min(max(left.max, right.smax), max(left.smax, right.max));

	return;
}

node query(node *tree, int start, int end, int treeNode, int left, int right){
	if(end < left || start > right){
		node ans;
		ans.max = INT_MIN;
		ans.smax = INT_MIN;
		// cout << "hello" << endl;
		return ans;
	}
	if(start >= left && end <= right){
		node ans;
		ans.max = tree[treeNode].max;
		ans.smax = tree[treeNode].smax;
		return ans;
	}
	
	// // cout << "hello1" << endl;
	// cout << start << " " << end << endl;    
	int mid = (start + end)/2;
	node ans1 = query(tree, start, mid, 2 * treeNode, left, right);
	node ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
	
	node ans;

	ans.max = max(ans1.max, ans2.max);
	ans.smax = min(max(ans1.max, ans2.smax), max(ans1.smax, ans2.max));
	return ans;
}

void update(int *arr, node *tree, int start, int end, int treeNode, int index, int value){
	if(start == end){
		tree[treeNode].max = value;
		arr[start] = value;
		return; 
	}
	int mid = (start + end)/2;
	if(index > mid){
		update(arr, tree, mid + 1, end, 2 * treeNode + 1, index, value);
	}
	else{
		update(arr, tree, start, mid, 2 * treeNode, index, value);
	}
	node ans1 = tree[2 * treeNode];
	node ans2 = tree[2 * treeNode + 1];
	tree[treeNode].max = max(ans1.max, ans2.max);
	tree[treeNode].smax = min(max(ans1.max, ans2.smax), max(ans1.smax, ans2.max));
	return;
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

	node *tree = new node[4 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	// for(int i = 1;i < 4 * n;i++){
	// 	cout << tree[i].max << " , " << tree[i].smax << endl;
	// }

	int q;
	cin >> q;
	while(q--){
		char a;
		int b, c;
		cin >> a >> b >> c;
		if(a == 'q'){
			cout << "q" << endl;
			node ans = query(tree, 0, n - 1, 1, b, c);
			cout << "qend" << endl;
			cout << ans.max + ans.smax << endl;
		}
		else{
			cout << "u" << endl;
			update(arr, tree, 0, n - 1, 1, b, c);
			// for(int i = 1;i < 4 * n;i++){
			// 	cout << tree[i].max << " , " << tree[i].smax << endl;
			// }
			cout << "uend" << endl;
		}
	}
	return 0;
}
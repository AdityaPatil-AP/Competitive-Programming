#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int low, int high, int startR, int endR, int currPos, int inc){

    if(low > high){
        return;
    }
    if(lazy[currPos] != 0){
        tree[currPos] += lazy[currPos];
        if(low != high){
            lazy[2 * currPos] += lazy[currPos];
            lazy[2 * currPos + 1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    // Completely outside or No Overlap
    if(high < startR || low > endR){
        return;
    } 
    // Complete Overlap
    if(startR <= low && high <= endR){
        tree[currPos] += inc;
        if(low != high){ 
            lazy[2 * currPos] += inc;
            lazy[2 * currPos + 1] += inc;
        }
        return;
    }
    // Partial Overlap
    int mid = (low + high)/2;
    updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2 * currPos, inc);
    updateSegmentTreeLazy(tree, lazy, mid + 1, high, startR, endR, 2 * currPos + 1, inc);

    tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\Cp Codes 1\\Cp Codes\\CpCourseCodesGithupRepo\\Cp\\input.txt","r", stdin);
    freopen("E:\\only one folder\\Cp Codes 1\\Cp Codes\\CpCourseCodesGithupRepo\\Cp\\output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int *tree = new int[4 * n]{};
    buildTree(arr, tree, 0, n - 1, 1);
    // cout << "Segment Tree : " << endl;
    // for(int i = 1;i < 4 * n;i++){
    //     cout << tree[i] << endl;
    // }

    int *lazy = new int[4 * n]{};
    updateSegmentTreeLazy(tree, lazy, 0, n - 1, 0, 3, 1, 3);
    updateSegmentTreeLazy(tree, lazy, 0, n - 1, 0, 1, 1, 2);
    cout << "Updated segment tree through Lazy Propogation :" <<endl;
    for(int i = 1;i < 4 * n;i++){
        cout << tree[i] << endl;
    }
    cout << "Lazy Tree : " << endl;
    for(int i = 1;i < 4 * n;i++){
        cout << lazy[i] << endl;
    }

    return 0;
}
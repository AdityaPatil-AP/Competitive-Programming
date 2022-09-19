/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root == NULL) return arr;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        stack<vector<int>> st;
        int levels = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* current = q.front();
                level.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                q.pop();
            }
            if(levels % 2 == 1) reverse(level.begin(), level.end());
            arr.push_back(level);
            levels++;
            level.clear();
        }

        return arr;
    }
};
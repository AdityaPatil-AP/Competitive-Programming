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
class Solution
{
public:
    string dfs(TreeNode *root, map<string, int> &mp, vector<TreeNode *> &ans)
    {
        if (root == NULL)
            return "";

        // first we will create the string representation for the left and the right child subtree.
        string left = dfs(root->left, mp, ans);
        string right = dfs(root->right, mp, ans);

        string curr = "(" + left + ")" + to_string(root->val) + "(" + right + ")";

        mp[curr]++;

        if (mp[curr] == 2)
        {
            ans.push_back(root);
        }
        return curr;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        map<string, int> mp;
        vector<TreeNode *> ans;

        dfs(root, mp, ans);
        return ans;
    }
};
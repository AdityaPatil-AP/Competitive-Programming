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
    map<int, int> cnt;
    int dfs(TreeNode *root, map<string, int> &mp, vector<TreeNode *> &ans)
    {
        if (root == NULL)
            return 0;

        // first we will create the string representation for the left and the right child subtree.
        int left = dfs(root->left, mp, ans);
        int right = dfs(root->right, mp, ans);

        // Creation of this string would take O(n) time.
        // and there are O(n) states so the time complexity will be O(n^2).
        // string curr = "(" + left + ")" + to_string(root->val) + "(" + right + ")";

        // Here we have proposed another technique which will do the above verification but in constant time.
        // We can keep a triplet instead of a string. The triplet will contain left subtree's id, root->val,
        // and right subtrees id. Every node will get an id for itself. If the same id is repeated twice.
        // Then we can add it to the ans because two nodes have the same structure meaning they are duplicate.

        string triplet = to_string(left) + "," + to_string(root->val) + "," + to_string(right);

        if (!mp.count(triplet))
        {
            mp[triplet] = mp.size() + 1;
        }
        int id = mp[triplet];

        cnt[id]++;

        // mp[curr]++;

        if (cnt[id] == 2)
        {
            ans.push_back(root);
        }
        return id;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // Here the only thing to understand was every node's subtree can be represented in the form
        // of a string. If the string occurences are stored in map and if they are occuring more than
        // once then the particular node is leading to a Duplicate Subtree.
        // Store it in the answer array.

        map<string, int> mp;
        vector<TreeNode *> ans;

        dfs(root, mp, ans);
        return ans;
    }
};
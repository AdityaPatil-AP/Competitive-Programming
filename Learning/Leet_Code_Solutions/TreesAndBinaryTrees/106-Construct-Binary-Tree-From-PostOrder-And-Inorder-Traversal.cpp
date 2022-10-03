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
    // Tip : use map to store the indexes of values.
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Index to denote the root of the current Tree
        int index = postorder.size() - 1;
        // Used map to store the indexes of values so that we can find them in O(1) time.
        map<int, int> mp;
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        // We are building the Tree
        return buildTree(inorder, postorder, 0, inorder.size() - 1, index, mp);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int> &postorder, int start, int end, int &index, map<int, int> &mp){
        // To denote there is atleast one node in the tree or else return NULL
        if(start > end) return NULL;
        // Creating the root Node  
        TreeNode* root = new TreeNode(postorder[index]);
        // Finding the pos of the root->val in the inorder array in O(1) time.
        int pos = mp[root->val];
        // Reducing the index to pass the new root to the right Subtree...
        index--;
        // Making Recursion Calls to Create the right Subtree first in this case and then the left Subtree 
        // Because in Preorder traversal - we have root at the last and then before it we have the root of the right Subtree.
        root->right = buildTree(inorder, postorder, pos + 1, end, index, mp);
        root->left = buildTree(inorder, postorder, start, pos - 1,index, mp);
        // Returning the Root as the answer.
        return root;
    }
};
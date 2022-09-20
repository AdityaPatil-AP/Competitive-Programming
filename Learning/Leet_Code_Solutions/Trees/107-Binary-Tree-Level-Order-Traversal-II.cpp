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
    // Tip : Whenever you are solving any question were you have to remember the next levels of the current node
    // use a queue generically. It may be tree question or a graph question.
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // The Levels of a Binary Tree stored in the 2d - vector
        vector<vector<int>> arr;
        // If root is null return the empty vector
        if(root == NULL) return arr;
        // For storing the TreeNodes we are declaring a queue of TreeNode pointers
        queue<TreeNode*> q;
        // We push the root at first.
        q.push(root);
        // q.push(NULL);
        // Storing the contents of the current level in the level vector.
        vector<int> level;
        // While the queue is not empty we have a level remaining so we enter the while loop.
        while(!q.empty()){
            // if(current == NULL){
            //     arr.push_back(level);
            //     level.clear();
            //     q.pop();
            //     if(q.empty()){
            //         break;
            //     }
            //     q.push(NULL);
            //     continue;
            // }
            // Using this approach at any instant we only have a specific level in the Binary Tree.
            // We just check the no. of elements in the queue and we push the node values in the level vector 
            // as well we start filling the next level in the queue but as the for loop is iterating for just the 
            // n - elements we don't pop the next level elements or add them into the level vector.
            int n = q.size();
            for(int i = 0;i < n;i++){
                TreeNode* current = q.front();
                level.push_back(current->val);
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);
                q.pop();
            }
            // We push the current level into the 2-d vector.
            arr.push_back(level);
            level.clear();
        }
        // We return the 2-d vector answer.
        return arr;
    }
};
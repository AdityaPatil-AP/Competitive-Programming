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
    // Here I have analysed five ways of doing this question.
    // Only some functions or technique would vary. Crux is the BFS and in one 
    // approach we use BFS.
    
    // 1) Using queue and reverse function.
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     // 2-d Vector for storing the answer
    //     vector<vector<int>> arr;
    //     // if root is null return empty arr
    //     if(root == NULL) return arr;
    //     // For Storing the children
    //     queue<TreeNode*> q;
    //     // pushing the first level.
    //     q.push(root);
    //     // For storing the individual level.
    //     vector<int> level;
    //     // Until the queue is not empty go in the loop as there is some node which have to 
    //     // be processed.
    //     while(!q.empty()){
    //         // Only the current level has to be considered for this time so we take the size of the 
    //         // queue already..
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             // Take the current node push into the level and then pushing the children into the 
    //             // queue. Popping the current node as well.
    //             TreeNode* current = q.front();
    //             level.push_back(current->val);
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }
    //         // At the last add that level in to the 2-d vector.
    //         arr.push_back(level);
    //         level.clear();
    //     }
    //     // Reversing the levels from bottom to up fashion now.
    //     reverse(arr.begin(), arr.end());
    //     return arr;
    // }
    
    // 2) Using Queue and insert function for 2-d Vector(adding current level at the start). - Very Slow
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //     // 2-d Vector for storing the answer
    //     vector<vector<int>> arr;
    //     // if root is null return empty arr
    //     if(root == NULL) return arr;
    //     // For Storing the children
    //     queue<TreeNode*> q;
    //     // pushing the first level.
    //     q.push(root);
    //     // For storing the individual level.
    //     vector<int> level;
    //     // Until the queue is not empty go in the loop as there is some node which have to 
    //     // be processed.
    //     while(!q.empty()){
    //         // Only the current level has to be considered for this time so we take the size of the 
    //         // queue already..
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             // Take the current node push into the level and then pushing the children into the 
    //             // queue. Popping the current node as well.
    //             TreeNode* current = q.front();
    //             level.push_back(current->val);
    //             if(current->left) q.push(current->left);
    //             if(current->right) q.push(current->right);
    //             q.pop();
    //         }
    //         // At the front add that current level in to the 2-d vector.
    //         arr.insert(arr.begin(), level);
    //         level.clear();
    //     }
    //     // Ultimately due to our unique of inserting the current levels at the first 
    //     // We already have the levels stored in the reverse order.
    //     return arr;
    // }
    
    // 3) Using Recursive Approach
    

};
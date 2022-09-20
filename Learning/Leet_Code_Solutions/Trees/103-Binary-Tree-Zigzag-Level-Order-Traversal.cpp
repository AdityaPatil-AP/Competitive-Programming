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
    
    // Using queue Bfs : But the space Complexity was high but time Complexity was 100%
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         // 2 -d vector creation
//         vector<vector<int>> arr;
//         if(root == NULL) return arr;
//         // Queue containing the TreeNode pointers.
//         queue<TreeNode*> q;
//         q.push(root);
//         // Storing the current level in the array
//         vector<int> level;
//         // The current level 
//         int levels = 0;
//         while(!q.empty()){
//             // No of elements in the current level
//             int n = q.size();
//             // Storing the elements of the current level in the level vector and adding their childrens to 
//             // queue.
//             for(int i = 0;i < n;i++){
//                 TreeNode* current = q.front();
//                 level.push_back(current->val);
//                 if(current->left) q.push(current->left);
//                 if(current->right) q.push(current->right);
//                 q.pop();
//             }
//             // Now we have formed the current level. It the parity of the level is odd 
//             // reverse it.
//             if(levels % 2 == 1) reverse(level.begin(), level.end());
//             arr.push_back(level);
//             levels++;
//             // Clear the level vector every time so as to add the next level.
//             level.clear();
//         }

//         return arr;
//     }
    
    // 2) Using Recursion
//     void zigzagLevelOrder(vector<vector<int>> &res, int level, TreeNode* root){
//         // If there is no node we don't require to add any level
//         if(!root) return;
//         // But if a node exists and the level in which it exists is not present we have to add the 
//         // level and then start push the elements of that level.
//         if(level >= res.size()){
//             res.push_back({});
//         }
//         // pushing the current root->val into that level.
//         res[level].push_back(root->val);
//         // Filling the res using the left and Right Subtree
//         zigzagLevelOrder(res, level + 1, root->left);
//         zigzagLevelOrder(res, level + 1, root->right);
//     }
    
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root){
//         vector<vector<int>> res;
//         if(!root) return res;
//         zigzagLevelOrder(res, 0, root);
//         // Reversing the odd levels
//         for(int i = 1;i < res.size();i+=2){
//             reverse(res[i].begin(), res[i].end());
//         }
//         return res;
//     }
    
    // Review Using Two Stacks
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        stack<TreeNode*> LtoR, RtoL;
        int lvl = 1;
        
        vector<vector<int>> ans;
        
        if(!root) return ans;

        RtoL.push(root);

        while(!RtoL.empty() || !LtoR.empty()) {
            
            vector<int> v;
            
            if(lvl % 2 == 1) {
                                
                while(!RtoL.empty()) {

                    TreeNode* curr = RtoL.top();
                    RtoL.pop();
                    v.push_back(curr -> val);

                    if(curr -> left) LtoR.push(curr -> left);
                    if(curr -> right) LtoR.push(curr -> right);        
                }   

            } else {
                
                while(!LtoR.empty()) {

                    TreeNode *curr = LtoR.top();
                    LtoR.pop();
                    v.push_back(curr -> val);

                    if(curr -> right) RtoL.push(curr -> right);
                    if(curr -> left) RtoL.push(curr -> left);                
                } 
            }
            
            ans.push_back(v);
            lvl++;
            
        }
        
        return ans;
    }
};
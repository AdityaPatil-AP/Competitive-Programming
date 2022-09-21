/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // 1) BFS
    // vector<vector<int>> levelOrder(Node* root) {
    //     vector<vector<int>> res;
    //     if(!root) return res;
    //     queue<Node*> q;
    //     q.push(root);
    //     vector<int> level;
    //     while(!q.empty()){
    //         int n = q.size();
    //         for(int i = 0;i < n;i++){
    //             Node* current = q.front();
    //             q.pop();
    //             level.push_back(current->val);
    //             for(int i = 0;i < (current->children).size();i++){
    //                 if(current->children[i]) q.push(current->children[i]);
    //             }
    //         }
    //         res.push_back(level);
    //         level.clear();
    //     }
    //     return res;
    // }
    
    // 2) Recursive DFS
//     void helper(Node* root, int level){
//         if(!root) return;
//         if(level >= res.size()){
//             res.push_back({});
//         }
//         res[level].push_back(root->val);
//         for(Node* child : root->children){
//             if(child) helper(child, level + 1);
//         }
//     }
    
//     vector<vector<int>> levelOrder(Node* root){
//         if(!root) return res;
//         helper(root, 0);
//         return res;
//     }
    
//     private:
//     vector<vector<int>> res;
//     int depth;
    
    // 3) Iterative BFS
    vector<vector<int>> levelOrder(Node* root){
        if(!root) return {};
        stack<pair<Node*, int>> st;
        vector<vector<int>> ans;
        st.push({root, 0});
        while(!st.empty()){
            const auto [node, level] = st.top(); 
            st.pop();
            if(level >= ans.size()){
                ans.push_back({node->val});   
            }
            else{
                ans[level].push_back(node->val);
            }
            // We need to push them in reverse order because the node which goes first 
            // comes out last.
            for(auto it = crbegin(node->children); it != crend(node->children);it++){
                st.push({*it, level + 1});
            }
        }
        return ans;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root) return {};

        vector<vector<int>> ans ;
        queue<TreeNode*> q1 ;
        queue<TreeNode*> q2 ;
        vector<int> temp ;

        q1.push(root);

        int refer = root->val ;

        while(!q1.empty()){
            TreeNode * curr = q1.front();
            q1.pop();
            temp.push_back(curr->val);

            if(curr->left){
                q2.push(curr->left);
            }

            if(curr->right){
                q2.push(curr->right);
            }

            if (q1.empty()){
                ans.push_back(temp);
                temp.clear();
                q1 = q2 ;
                q2 = queue<TreeNode *>();
            }
        }

        return ans ;
    }

};

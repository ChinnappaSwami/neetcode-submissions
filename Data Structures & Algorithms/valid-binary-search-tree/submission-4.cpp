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
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true ;

        return (isValidLeft(root , root->left) && isValidRight(root , root->right) && isValidBST(root->left) && isValidBST(root->right)) ;
    }

    bool isValidLeft(TreeNode* root , TreeNode* l){

        if(!l) return true ;
        if (root->val <= l->val) return false ;

        return isValidLeft(root , l->left) && isValidLeft(root , l->right);
    }

    bool isValidRight(TreeNode* root , TreeNode* r){

        if(!r) return true ;
        if (root->val >= r->val) return false ;

        return isValidRight(root , r->left) && isValidRight(root , r->right);
    }
};

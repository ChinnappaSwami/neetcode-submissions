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
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        
        if(in.empty()) return nullptr ;

        auto inoind = find(in.begin() , in.end() , pr[0]);
        int index = inoind - in.begin();
        vector<int> il(in.begin() , in.begin() + index ) ;
        vector<int> ir(in.begin() + index + 1, in.end());

        vector<int> pl(pr.begin() + 1 , pr.begin() + index + 1);
        vector<int> pri(pr.begin() + index + 1, pr.end());

        TreeNode* root = new TreeNode(pr[0] , buildTree( pl , il) , buildTree( pri , ir));       

        return root ;
    }
};

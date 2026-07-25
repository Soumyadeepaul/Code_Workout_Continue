//https://leetcode.com/problems/merge-two-binary-trees/description/


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
    TreeNode* helper(TreeNode* root1, TreeNode* root2){
        if(root1 && root2){
            TreeNode* n=new TreeNode(root1->val+root2->val);
            n->left=helper(root1->left,root2->left);
            n->right=helper(root1->right,root2->right);
            return n;
        }
        else if(root1 && !root2){
            return root1;
        }
        else if(!root1 && root2) return root2;
        else return nullptr;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return helper(root1,root2);
    }
};

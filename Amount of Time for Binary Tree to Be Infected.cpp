//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/


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
    int below(TreeNode* node){ //maxHeight
        if(node==nullptr) return 0;
        return 1+max(below(node->left),below(node->right));
    }
    int result=INT_MIN;
    stack<TreeNode*> store;
    void helper(TreeNode* root, int start){
        if(root==nullptr) return;
        store.push(root);
        if(root->val==start){
            result=max(result,below(root))-1; //self is already infected
            above(start);
            return;
        }
        else{
            helper(root->left,start);
            helper(root->right,start);
        }
        if(!store.empty()) store.pop();
    }

    void above(int start){
        int mHeight=0;
        int additional=0;
        TreeNode* prev=store.top();
        store.pop();
        while(!store.empty()){
            TreeNode* top=store.top();
            store.pop();
            if(top->left==prev){
                top->left=nullptr;
            }
            else{
                top->right=nullptr;
            }
            additional++;
            result=max(result,additional+below(top)-1);
            prev=top;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        helper(root,start);
        return result;
    }
};

//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/


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
    stack<TreeNode*> stacked;
    string result = "";

    bool helper(TreeNode* root, int p) {
        if (!root) return false;

        stacked.push(root);

        if (root->val == p) return true;

        if (helper(root->left, p)) return true;
        if (helper(root->right, p)) return true;

        stacked.pop();
        return false;
    }

    bool preorder(TreeNode* node, int q, string &path) {
        if (!node) return false;

        if (node->val == q) {
            result = path;
            return true;
        }

        path.push_back('L');
        if (preorder(node->left, q, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (preorder(node->right, q, path)) return true;
        path.pop_back();

        return false;
    }

    void uporder(int q) {
        TreeNode* prev = stacked.top();
        stacked.pop();

        string up = "";

        while (!stacked.empty()) {
            up.push_back('U');

            TreeNode* curr = stacked.top();

            if (curr->left == prev) {
                curr->left = nullptr;

                string path = "";
                if (preorder(curr, q, path)) {
                    result = up + result;
                    curr->left = prev;
                    return;
                }

                curr->left = prev;
            }
            else {
                curr->right = nullptr;

                string path = "";
                if (preorder(curr, q, path)) {
                    result = up + result;
                    curr->right = prev;
                    return;
                }

                curr->right = prev;
            }

            prev = curr;
            stacked.pop();
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        helper(root, startValue);

        string path = "";
        if (preorder(stacked.top(), destValue, path))
            return result;

        uporder(destValue);

        return result;
    }
};

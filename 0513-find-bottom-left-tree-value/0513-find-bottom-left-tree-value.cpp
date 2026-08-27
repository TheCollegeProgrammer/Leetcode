/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int value = -1;
    int curr = -1;

    void travel(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        if (level > curr) {
            curr = level;
            value = root->val;
        }

        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        value = root->val;
        travel(root, 0);
        return value;
    }
};
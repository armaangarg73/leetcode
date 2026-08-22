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
   int best = 0;

    int arrow(TreeNode* node) {
        if (node == NULL)
            return 0;

        int lRaw = arrow(node->left);
        int rRaw = arrow(node->right);

        int lArm = 0;
        int rArm = 0;

        if (node->left != NULL && node->left->val == node->val)
            lArm = lRaw + 1;

        if (node->right != NULL && node->right->val == node->val)
            rArm = rRaw + 1;

        best = max(best, lArm + rArm);

        return max(lArm, rArm);
    }

    int longestUnivaluePath(TreeNode* root) {
        arrow(root);
        return best;
    }
};
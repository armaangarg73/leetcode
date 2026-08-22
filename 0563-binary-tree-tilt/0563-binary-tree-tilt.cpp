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
     int total = 0;

    int sum(TreeNode* node) {
        if (node == NULL)
            return 0;

        int sumL = sum(node->left);
        int sumR = sum(node->right);

        total += abs(sumL - sumR);

        return node->val + sumL + sumR;
    }

    int findTilt(TreeNode* root) {
        sum(root);
        return total;
    }
};
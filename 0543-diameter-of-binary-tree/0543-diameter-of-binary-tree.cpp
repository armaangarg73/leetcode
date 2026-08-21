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

    int height(TreeNode* node) {

        if(node == NULL) {
            return -1;
        }

        int L = height(node->left);
        int R = height(node->right);

        best = max(best, (L + 1) + (R + 1));

        return 1 + max(L, R);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return best;
    }
    
};
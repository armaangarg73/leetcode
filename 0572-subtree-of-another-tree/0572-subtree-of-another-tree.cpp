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

    bool isSameTree(TreeNode* p , TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true ;
        }
        if(p == NULL || q == NULL) {
            return false ;
        }

        if(p->val!=q->val){
            return false ;
        }

       bool r1 = isSameTree(p->left , q->left);
       bool r2 = isSameTree(p->right , q->right);

       if(r1 == true && r2 == true) {
        return true;
       }
       return false ;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true ;
        if(root == NULL) return false ;

        if(isSameTree(root, subRoot)) return true;
        if(isSubtree(root->left, subRoot)) return true;
        return isSubtree(root->right, subRoot);

    }
};
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

    // void invertTree(TreeNode* root) {
    //      if(root == NULL) {
    //         return  ;
    //     }

    //     swap(root->left , root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);
    // }

    //  bool isSameTree(TreeNode* p , TreeNode* q) {
    //     if(p == NULL && q == NULL) {
    //         return true ;
    //     }
    //     if(p == NULL || q == NULL) {
    //         return false ;
    //     }

    //     if(p->val!=q->val){
    //         return false ;
    //     }

    //    bool r1 = isSameTree(p->left , q->left);
    //    bool r2 = isSameTree(p->right , q->right);

    //    if(r1 == true && r2 == true) {
    //     return true;
    //    }
    //    return false ;
    // }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
          if(root1 == NULL && root2 == NULL) return true;

        if(root1 == NULL || root2 == NULL) return false;

        if(root1->val != root2->val) return false;

        if(flipEquiv(root1->left, root2->left) &&
           flipEquiv(root1->right, root2->right)) {
            return true;
        }

        if(flipEquiv(root1->left, root2->right) &&
           flipEquiv(root1->right, root2->left)) {
            return true;
        }

        return false;
    }
};
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        if (root->val == subRoot->val) {
            if (helper(root, subRoot)) return true;
        }

        return isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }

    bool helper(TreeNode* p1, TreeNode* p2) {
        if (p1 == NULL && p2 == NULL) return true;
        if (p1 == NULL || p2 == NULL) return false;

        if (p1->val != p2->val) return false;

        return helper(p1->left, p2->left) && 
               helper(p1->right, p2->right);
    }
};
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
    TreeNode* pop_front(vector<TreeNode*>& vec) {
        if (!vec.empty()) {
            TreeNode* temp = vec.front();
            vec.erase(vec.begin());
            return temp;
        }
        return nullptr;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        vector<TreeNode*> q;

        if (root == nullptr) return levels;

        q.push_back(root);

        while (!q.empty()) {
            vector<TreeNode*> level;
            vector<int> vals;

            int n = q.size(), c = 0;

            while (c < n) {
                TreeNode* temp = pop_front(q);

                level.push_back(temp);
                vals.push_back(temp->val);

                if (temp->left != NULL)
                    q.push_back(temp->left);

                if (temp->right != NULL)
                    q.push_back(temp->right);

                c++;
            }

            levels.push_back(vals);
        }

        return levels;
    }
};
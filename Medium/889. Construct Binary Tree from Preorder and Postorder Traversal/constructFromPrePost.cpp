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
        void buildTree(TreeNode* root, vector<int>& preorder,
                       vector<int>& postorder) {
    
            if (postorder.back() == root->val) {
                postorder.pop_back();
                return;
            }
    
            root->left = new TreeNode(preorder.back());
            preorder.pop_back();
            buildTree(root->left, preorder, postorder);
    
            if (postorder.back() == root->val) {
                postorder.pop_back();
                return;
            }
    
            root->right = new TreeNode(preorder.back());
            preorder.pop_back();
            buildTree(root->right, preorder, postorder);
    
            postorder.pop_back();
            return;
        }
    
        TreeNode* constructFromPrePost(vector<int>& preorder,
                                       vector<int>& postorder) {
            reverse(preorder.begin(), preorder.end());
            reverse(postorder.begin(), postorder.end());
            TreeNode* tree = new TreeNode(preorder.back());
            preorder.pop_back();
            buildTree(tree, preorder, postorder);
            return tree;
        }
    };
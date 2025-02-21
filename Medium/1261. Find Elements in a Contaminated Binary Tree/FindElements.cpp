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
class FindElements {
    TreeNode* tree;

public:
    FindElements(TreeNode* root) { tree = root; }

    bool find(int target) {
        vector<bool> steps(((int8_t)log2(target + 1)), false);
        int8_t idx = 0;
        while (target > 0) {
            if (target % 2 > 0) {
                target /= 2;
            } else {
                target /= 2;
                target--;
                steps[idx] = true;
            }
            idx++;
        }
        TreeNode* root = tree;
        for (idx--; idx >= 0; --idx) {
            if (steps[idx]) {
                root = root->right;
            } else {
                root = root->left;
            }
            if (root == nullptr) {
                return false;
            }
        }
        return true;
    }
};

class FindElements2 {
    unordered_set<int> falseMap;

public:
    FindElements2(TreeNode* root) {
        root->val = 0;
        recoverElements(root, falseMap);
    }

    void recoverElements(TreeNode* root, unordered_set<int>& falseMap) {
        falseMap.insert(root->val);
        if (root->left != nullptr) {
            root->left->val = (root->val) * 2 + 1;
            recoverElements(root->left, falseMap);
        }
        if (root->right != nullptr) {
            root->right->val = (root->val) * 2 + 2;
            recoverElements(root->right, falseMap);
        }
    }

    bool find(int target) { return (falseMap.count(target) > 0); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
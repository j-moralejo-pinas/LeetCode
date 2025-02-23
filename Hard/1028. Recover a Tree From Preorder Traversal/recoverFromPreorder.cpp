
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
        void parseNext(string& traversal, pair<uint32_t, uint8_t>& val_depth) {
            val_depth.first = 0;
            if (traversal.size() == 0) {
                return;
            }
            val_depth.second = 0;
            bool depthFinished = false;
    
            while (traversal.size() > 0) {
                if (traversal.back() == '-') {
                    if (depthFinished) {
                        break;
                    }
                    val_depth.second++;
                } else {
                    depthFinished = true;
                    val_depth.first =
                        val_depth.first * 10 + (traversal.back() - '0');
                }
                traversal.pop_back();
            }
        }
    
        void exploreTree(string& traversal, TreeNode* root, uint8_t currDepth,
                         pair<uint32_t, uint8_t>& val_depth) {
            parseNext(traversal, val_depth);
            currDepth++;
            if (currDepth == val_depth.second) {
                root->left = new TreeNode(val_depth.first);
                exploreTree(traversal, root->left, currDepth , val_depth);
    
                if (val_depth.first > 0) {
                    if (currDepth == val_depth.second) {
                        root->right = new TreeNode(val_depth.first);
                        exploreTree(traversal, root->right, currDepth ,
                                    val_depth);
                    }
                }
            }
        }
    
        TreeNode* recoverFromPreorder(string traversal) {
            reverse(traversal.begin(), traversal.end());
            pair<uint32_t, uint8_t> val_depth = {0, 0};
            parseNext(traversal, val_depth);
            TreeNode* root = new TreeNode(val_depth.first);
            exploreTree(traversal, root, 0, val_depth);
            return root;
        }
    };
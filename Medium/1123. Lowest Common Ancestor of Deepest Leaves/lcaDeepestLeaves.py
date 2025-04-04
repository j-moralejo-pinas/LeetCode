# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfs(self, node: Optional[TreeNode], curr_depth: int) -> Tuple[int, int]:
        if node is None:
            return curr_depth, -1

        l_best_depth, l_best_ancestor = self.dfs(node.left, curr_depth+1)
        r_best_depth, r_best_ancestor = self.dfs(node.right, curr_depth+1)

        if l_best_depth > r_best_depth:
            return l_best_depth, l_best_ancestor
        elif r_best_depth > l_best_depth:
            return r_best_depth, r_best_ancestor
        return l_best_depth, node

    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root, 0)[1]
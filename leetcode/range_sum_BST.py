# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        
        if root == None:
            return 0
        
        # For out of range values
        if root.val < L:
            rightSum = self.rangeSumBST(root.right, L, R)
            return rightSum
        elif root.val > R:
            leftSum = self.rangeSumBST(root.left, L, R)
            return leftSum
            
        # for in range values
        else:
            leftSum = self.rangeSumBST(root.left, L, R)
            rightSum = self.rangeSumBST(root.right, L, R)
            total = root.val + leftSum + rightSum
    
        return total
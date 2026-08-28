##https://leetcode.com/problems/binary-tree-tilt/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        
        result=0
        def helper(node):
            nonlocal result
            
            if node!=None:
                l=helper(node.left)
                r=helper(node.right)
                n=node.val
                node.val=abs(l-r)
                
                result+=node.val

                return l+r+n

            return 0
        
        helper(root)

        return result

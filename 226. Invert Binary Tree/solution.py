class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return None
        
        if root.left:
            self.invertTree(root.left)
        if root.right:
            self.invertTree(root.right)
        
        root.left, root.right = root.right, root.left
        return root

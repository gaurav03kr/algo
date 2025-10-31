"""
LeetCode Problem: 145: Binary Tree Postorder Traversal
Problem Summary:
Given the root of a binary tree, return its postorder traversal (Left -> Right -> Root).
Example 1:
Input: root = [1,None,2,3]
Output: [3,2,1]
Example 2:
Input: root = []
Output: []
Example 3:
Input: root = [1]
Output: [1]
Approach:
We can use recursion or an iterative approach using a stack. Here we use recursion:
1. Traverse the left subtree recursively.
2. Traverse the right subtree recursively.
3. Visit the current node and append its value to the result.
Time Complexity: O(N), where N is the number of nodes
Space Complexity: O(H), where H is the height of the tree (recursion stack)
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root):
        result = []

        def postorder(node):
            if not node:
                return
            postorder(node.left)
            postorder(node.right)
            result.append(node.val)

        postorder(root)
        return result


# for testing...
def build_tree(values):
    """Helper function to build a binary tree from a list (level-order)."""
    if not values:
        return None
    nodes = [TreeNode(val) if val is not None else None for val in values]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids: node.left = kids.pop()
            if kids: node.right = kids.pop()
    return root

if __name__ == "__main__":
    print("Enter tree nodes in level order (use 'None' for nulls, space-separated):")
    vals = input().split()
    vals = [int(x) if x != 'None' else None for x in vals]
    root = build_tree(vals)

    sol = Solution()
    result = sol.postorderTraversal(root)
    print(f"Postorder Traversal: {result}")

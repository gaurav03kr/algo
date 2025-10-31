"""
LeetCode Problem: 100: Same Tree
Problem Summary:
Given the roots of two binary trees p and q, write a function to check if they are the same.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
Approach:
We use recursion to compare the two trees:
1. If both nodes are None, return True (both trees are empty at this node).
2. If one node is None and the other is not, return False.
3. If the values of the current nodes are different, return False.
4. Recursively check the left and right subtrees.
Time Complexity: O(min(N, M)), where N and M are the number of nodes in p and q
Space Complexity: O(h), where h is the height of the tree (due to recursion stack)
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


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
    print("Enter tree 1 nodes in level order (use 'None' for nulls, space-separated):")
    p_vals = input().split()
    p_vals = [int(x) if x != 'None' else None for x in p_vals]
    p_root = build_tree(p_vals)

    print("Enter tree 2 nodes in level order (use 'None' for nulls, space-separated):")
    q_vals = input().split()
    q_vals = [int(x) if x != 'None' else None for x in q_vals]
    q_root = build_tree(q_vals)

    sol = Solution()
    result = sol.isSameTree(p_root, q_root)
    print(f"Are the two trees the same? {result}")

"""
LeetCode Problem: 103: Binary Tree Zigzag Level Order Traversal
Problem Summary:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
Example 1:
Input: root = [3,9,20,None,None,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
Approach:
We use a breadth-first search (BFS) approach with a queue:
1. Use a queue to traverse the tree level by level.
2. Keep a flag `left_to_right` to determine the order of insertion for each level.
3. For each level:
   a. Collect node values in a temporary list.
   b. If `left_to_right` is False, reverse the temporary list.
   c. Append the temporary list to the result.
   d. Toggle `left_to_right` for the next level.
Time Complexity: O(N), where N is the number of nodes
Space Complexity: O(N) for the queue and result
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):
        if not root:
            return []

        result = []
        queue = deque([root])
        left_to_right = True

        while queue:
            level_size = len(queue)
            level = []

            for _ in range(level_size):
                node = queue.popleft()
                level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)

            if not left_to_right:
                level.reverse()
            result.append(level)
            left_to_right = not left_to_right

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
    result = sol.zigzagLevelOrder(root)
    print(f"Zigzag Level Order Traversal: {result}")

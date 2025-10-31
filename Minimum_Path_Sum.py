"""
LeetCode Problem: 64: Minimum Path Sum

Problem Summary:
Given a m x n grid filled with non-negative numbers, find a path from top-left to bottom-right
which minimizes the sum of all numbers along its path. You can only move either down or right.

Example 1:
Input: grid = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Approach:
We use dynamic programming (DP) to build a table dp where dp[i][j] is the minimum path sum
to reach cell (i,j):
1. Initialize dp[0][0] = grid[0][0].
2. Fill the first row: dp[0][j] = dp[0][j-1] + grid[0][j].
3. Fill the first column: dp[i][0] = dp[i-1][0] + grid[i][0].
4. For other cells: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).
5. Return dp[m-1][n-1] as the result.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
"""

class Solution:
    def minPathSum(self, grid):
        if not grid or not grid[0]:
            return 0

        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]

        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]

        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

        return dp[m-1][n-1]


# for testing...
if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))
    print("Enter the grid row by row (space-separated integers):")
    grid = []
    for _ in range(m):
        row = list(map(int, input().split()))
        grid.append(row)

    sol = Solution()
    result = sol.minPathSum(grid)
    print(f"Minimum Path Sum: {result}")

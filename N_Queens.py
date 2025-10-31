"""
LeetCode Problem: 51: N-Queens
Problem Summary:
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' indicate a queen and an empty space respectively.
Example 1:
Input: n = 4
Output: [
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]
Example 2:
Input: n = 1
Output: [["Q"]]
Approach:
We use backtracking to try placing queens row by row:
1. Use three sets to track occupied columns, positive diagonals (r+c), and negative diagonals (r-c).
2. For each row, try placing a queen in each column:
   a. If the column or diagonal is occupied, skip.
   b. Otherwise, place the queen and mark the column and diagonals as occupied.
   c. Recurse for the next row.
   d. Backtrack by removing the queen and freeing the column/diagonals.
3. When all n rows are filled, add the current board configuration to the result.
Time Complexity: O(N!) in the worst case
Space Complexity: O(N^2) for storing results and O(N) for tracking columns/diagonals
"""

class Solution:
    def solveNQueens(self, n):
        def backtrack(row):
            if row == n:
                board = []
                for r in range(n):
                    line = ['.'] * n
                    line[queens[r]] = 'Q'
                    board.append("".join(line))
                result.append(board)
                return
            
            for col in range(n):
                if col in cols or (row + col) in pos_diag or (row - col) in neg_diag:
                    continue
                queens[row] = col
                cols.add(col)
                pos_diag.add(row + col)
                neg_diag.add(row - col)
                backtrack(row + 1)
                # backtrack
                cols.remove(col)
                pos_diag.remove(row + col)
                neg_diag.remove(row - col)
        
        result = []
        queens = [-1] * n
        cols = set()
        pos_diag = set()
        neg_diag = set()
        backtrack(0)
        return result


# for testing...
if __name__ == "__main__":
    n = int(input("Enter the value of n for N-Queens: "))
    sol = Solution()
    solutions = sol.solveNQueens(n)
    print(f"Total solutions: {len(solutions)}")
    for idx, board in enumerate(solutions, 1):
        print(f"\nSolution {idx}:")
        for line in board:
            print(line)

"""
LeetCode Problem: 118: Pascal's Triangle

Problem Summary:
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Approach:
1. Initialize an empty list `triangle`.
2. For each row from 0 to numRows-1:
    a. Start the row with 1.
    b. For each element between first and last, compute it as the sum of the two elements above.
    c. End the row with 1.
3. Append the row to the triangle.

Time Complexity: O(numRows^2) – each row has up to row elements
Space Complexity: O(numRows^2) – storing all elements of the triangle
"""

class Solution:
    def generate(self, numRows: int):
        triangle = []
        for row_num in range(numRows):
            row = [1] * (row_num + 1)
            for j in range(1, row_num):
                row[j] = triangle[row_num - 1][j - 1] + triangle[row_num - 1][j]
            triangle.append(row)
        return triangle



numRows = int(input("Enter number of rows for Pascal's Triangle: "))
sol = Solution()
result = sol.generate(numRows)
print(f"Pascal's Triangle with {numRows} rows:")
for row in result:
    print(row)

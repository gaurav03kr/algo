/*
LeetCode Problem: 1143: Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters

Approach:
We use recursion with memoization (top-down dynamic programming).

1. Define a recursive function `rec(i, j)` that returns the length of the LCS
   between the suffixes text1[i:] and text2[j:].
2. Base case: If either string is fully traversed, return 0.
3. If characters match (text1[i] == text2[j]), include this character and move both indices forward.
4. Otherwise, take the maximum result of skipping one character from either string.
5. Store computed results in a dp table to avoid recomputation.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
where n = length of text1, m = length of text2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];  
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, text1, text2);
    }

    int rec(int i, int j, string &l1, string &l2) {
        if (i >= l1.size() || j >= l2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (l1[i] == l2[j])
            return dp[i][j] = 1 + rec(i + 1, j + 1, l1, l2);

        return dp[i][j] = max(rec(i + 1, j, l1, l2), rec(i, j + 1, l1, l2));
    }
};

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    Solution sol;
    int result = sol.longestCommonSubsequence(s1, s2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}

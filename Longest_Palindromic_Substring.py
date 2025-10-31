"""
LeetCode Problem: 5: Longest Palindromic Substring

Problem Summary:
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab" or "aba"

Example 2:
Input: s = "cbbd"
Output: "bb"

Approach:
We expand around every possible center of the palindrome.

1. Each character can be the center of an odd-length palindrome.
2. Each pair of identical adjacent characters can be the center of an even-length palindrome.
3. For each center, expand outwards while characters match.
4. Keep track of the longest palindrome found.

Time Complexity: O(n²)
Space Complexity: O(1)
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        def expand_around_center(s: str, left: int, right: int):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1

        start = 0
        end = 0

        for i in range(len(s)):
            odd = expand_around_center(s, i, i)       # Odd-length palindrome
            even = expand_around_center(s, i, i + 1)  # Even-length palindrome
            max_len = max(odd, even)
            
            if max_len > end - start:
                start = i - (max_len - 1) // 2
                end = i + max_len // 2
        
        return s[start:end + 1]


# for testing...
if __name__ == "__main__":
    s = input("Enter a string: ")
    sol = Solution()
    result = sol.longestPalindrome(s)
    print(f"Longest Palindromic Substring: {result}")

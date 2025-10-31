"""
LeetCode Problem: 1400: Construct K Palindrome Strings

Problem Statement:
Given a string s and an integer k, return True if you can use all the characters in s
to construct non-empty k palindrome strings, or False otherwise.

Example 1:
Input: s = "annabelle", k = 2
Output: True
Explanation:
You can construct two palindromes using all characters in s.
Some possible constructions:
- "anna" + "elble"
- "anbna" + "elle"
- "anellena" + "b"

Example 2:
Input: s = "leetcode", k = 3
Output: False
Explanation:
It is impossible to construct 3 palindromes using all characters of s.

Example 3:
Input: s = "true", k = 4
Output: True
Explanation:
The only possible solution is to put each character in a separate string.

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= 10^5

Approach:
1. If k > len(s), return False — you can’t form more palindromes than characters.
2. Count character frequencies using Counter.
3. Count how many characters have odd frequencies (odd_count).
   Each odd-count character must go in a separate palindrome.
4. If odd_count <= k, return True; otherwise, return False.

Time Complexity: O(n)
Space Complexity: O(1)
"""

from collections import Counter

def canConstruct(s: str, k: int) -> bool:
    if k > len(s):
        return False

    freq = Counter(s)

    odd_count = sum(1 for v in freq.values() if v % 2 != 0)

    return odd_count <= k


# ------------------- Example Runs -------------------
if __name__ == "__main__":
    test_cases = [
        ("annabelle", 2),
        ("leetcode", 3),
        ("true", 4),
        ("aabbcc", 3),
        ("abc", 1)
    ]

    for s, k in test_cases:
        print(f"s = '{s}', k = {k} -> {canConstruct(s, k)}")

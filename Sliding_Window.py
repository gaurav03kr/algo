"""
Algorithm Concept: Sliding Window Technique
Problem Example: Maximum Sum Subarray of Size K
Problem Summary:
Given an array of integers `arr` and an integer `k`, find the maximum sum of any contiguous subarray of size k.
Example 1:
Input: arr = [2, 1, 5, 1, 3, 2], k = 3
Output: 9
Explanation: Subarray [5, 1, 3] has the maximum sum = 9.
Example 2:
Input: arr = [1, 9, -1, -2, 7, 3, -1, 2], k = 4
Output: 13
Explanation: Subarray [9, -1, -2, 7] has the maximum sum = 13.
Approach:
We use the Sliding Window technique to efficiently compute the maximum sum of subarrays of size k:
1. Initialize a window sum of the first k elements.
2. Slide the window one element at a time:
   - Subtract the element that is left behind.
   - Add the new element entering the window.
3. Keep track of the maximum window sum found so far.
This approach avoids recalculating sums from scratch for every subarray.
Time Complexity: O(n)
Space Complexity: O(1)
"""

def max_sum_subarray(arr, k):
    n = len(arr)
    if n < k:
        print("Window size must be smaller than or equal to array size.")
        return 0

    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, n):
        window_sum += arr[i] - arr[i - k]
        max_sum = max(max_sum, window_sum)

    return max_sum


# for testing...
if __name__ == "__main__":
    arr = list(map(int, input("Enter array elements (space-separated): ").split()))
    k = int(input("Enter window size k: "))
    result = max_sum_subarray(arr, k)
    print(f"Maximum sum of a subarray of size {k}: {result}")

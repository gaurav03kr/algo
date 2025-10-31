"""
Problem: Sieve of Eratosthenes
Problem Summary:
Given an integer n, return all prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm.
Example 1:
Input: n = 10
Output: [2, 3, 5, 7]
Example 2:
Input: n = 1
Output: []
Example 3:
Input: n = 20
Output: [2, 3, 5, 7, 11, 13, 17, 19]
Approach:
1. Create a boolean array `is_prime` of size n+1 initialized to True.
2. Set is_prime[0] and is_prime[1] to False (0 and 1 are not prime).
3. For each number p from 2 to sqrt(n):
    a. If is_prime[p] is True, mark all multiples of p (starting from p*p) as False.
4. All indices i where is_prime[i] is True are prime numbers.
Time Complexity: O(n log log n)
Space Complexity: O(n)
"""

def sieve_of_eratosthenes(n):
    if n < 2:
        return []

    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for multiple in range(p*p, n+1, p):
                is_prime[multiple] = False

    primes = [i for i, prime in enumerate(is_prime) if prime]
    return primes


n = int(input("Enter n: "))
primes = sieve_of_eratosthenes(n)
print(f"Primes up to {n}: {primes}")

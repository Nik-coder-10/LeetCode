from math import gcd

class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return gcd(n * n, n * (n + 1))
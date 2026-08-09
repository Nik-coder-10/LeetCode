class Solution:
    def mirrorDistance(self, n: int) -> int:
        x = n
        r = 0

        while x:
            r = r * 10 + x % 10
            x //= 10

        return abs(n - r)
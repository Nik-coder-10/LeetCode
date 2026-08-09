class Solution:
    def mirrorDistance(self, n: int) -> int:
        r = int(str(n)[::-1])
        return abs(n - r)
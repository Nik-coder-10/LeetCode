from math import gcd

class Solution:
    def gcdSum(self, nums: List[int]) -> int:
        a = []
        mx = 0

        for x in nums:
            mx = max(mx, x)
            a.append(gcd(x, mx))

        a.sort()

        ans = 0
        i, j = 0, len(a) - 1
        while i < j:
            ans += gcd(a[i], a[j])
            i += 1
            j -= 1

        return ans
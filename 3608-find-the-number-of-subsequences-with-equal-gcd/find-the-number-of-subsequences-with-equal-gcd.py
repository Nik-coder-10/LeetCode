class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        from functools import cache
        from math import gcd

        MOD = 10 ** 9 + 7

        @cache
        def dp(i, g1, g2):
            if i == len(nums):
                return 1 if g1 == g2 and g1 != 0 else 0

            ans = dp(i + 1, g1, g2)

            ng1 = nums[i] if g1 == 0 else gcd(g1, nums[i])
            ans += dp(i + 1, ng1, g2)

            ng2 = nums[i] if g2 == 0 else gcd(g2, nums[i])
            ans += dp(i + 1, g1, ng2)

            return ans % MOD

        return dp(0, 0, 0)
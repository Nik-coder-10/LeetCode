class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        s = sum(nums)
        ans = 0

        while s % k != 0:
            s -= 1
            ans += 1

        return ans
        
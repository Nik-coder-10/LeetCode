class Solution:
    def isGood(self, nums: List[int]) -> bool:
        nums.sort()
        n = len(nums)

        return nums == list(range(1, n)) + [n - 1]
class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        s = nums[0]
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1] + 1:
                break
            s += nums[i]
        while s in nums:
            s += 1
        return s
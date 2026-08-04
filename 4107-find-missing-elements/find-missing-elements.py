class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        ans = []

        for x in range(min(nums), max(nums) + 1):
            if x not in nums:
                ans.append(x)

        return ans
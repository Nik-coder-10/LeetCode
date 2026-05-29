class Solution:
    def minElement(self, nums: List[int]) -> int:
        req = []

        for i in range(len(nums)):
            summ = sum(int(d) for d in str(nums[i]))
            req.append(summ)

        return min(req)
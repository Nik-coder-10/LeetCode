class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:

        triplets = []

        nums.sort()

        for indx, val in enumerate(nums):
            if (indx>0) & (val == nums[indx-1]):
                continue
            left = ( indx + 1)
            right = (len(nums) - 1)

            while left < right:
                currentSum = val + nums[left] + nums[right]

                if currentSum > 0:
                    right -= 1
                elif currentSum < 0:
                    left += 1
                else:
                    triplets.append([val, nums[left], nums[right]])
                    left += 1
                    while (left < right) & ( nums[left] == nums[left-1]):
                        left +=1
        return triplets
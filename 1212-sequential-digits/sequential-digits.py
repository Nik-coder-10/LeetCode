class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []

        for length in range(2, 10):
            for start in range(1, 11 - length):
                num = 0
                for digit in range(start, start + length):
                    num = num * 10 + digit

                if low <= num <= high:
                    ans.append(num)

        return ans
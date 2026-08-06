class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            prod = 1
            x = n

            while x:
                prod *= x % 10
                x //= 10

            if prod % t == 0:
                return n

            n += 1
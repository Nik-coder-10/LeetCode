class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1

        b = bin(n)[2:]
        ans = ""

        for c in b:
            if c == '0':
                ans += '1'
            else:
                ans += '0'

        return int(ans, 2)
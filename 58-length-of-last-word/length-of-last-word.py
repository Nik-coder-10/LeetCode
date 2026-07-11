class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s[::-1]
        i = 0
        count = 0

        while i < len(a) and a[i] == ' ':
            i += 1

        while i < len(a) and a[i] != ' ':
            count += 1
            i += 1

        return count
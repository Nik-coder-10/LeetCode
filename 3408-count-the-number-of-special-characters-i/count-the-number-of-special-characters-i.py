class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count = 0

        for ch in set(word):
            if ch.islower() and ch.swapcase() in word:
                count += 1

        return count
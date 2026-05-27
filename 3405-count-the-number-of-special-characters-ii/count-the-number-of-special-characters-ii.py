class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count = 0

        for ch in set(word):
            if ch.islower():
                if ch.swapcase() in word:
                    if word.rfind(ch) < word.find(ch.swapcase()):
                        count += 1

        return count
        
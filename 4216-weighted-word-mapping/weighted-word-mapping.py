class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []

        for word in words:
            total = 0

            for ch in word:
                total = (total + weights[ord(ch) - ord('a')]) % 26

            ans.append(chr(ord('a') + 25 - total))

        return "".join(ans)
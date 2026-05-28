class Trie:
    def __init__(self):
        self.child = {}
        self.idx = -1


class Solution:
    def stringIndices(self, wordsContainer, wordsQuery):
        root = Trie()

        for i, w in enumerate(wordsContainer):
            node = root

            if (node.idx == -1 or
                len(w) < len(wordsContainer[node.idx])):
                node.idx = i

            for ch in w[::-1]:
                if ch not in node.child:
                    node.child[ch] = Trie()

                node = node.child[ch]

                if (node.idx == -1 or
                    len(w) < len(wordsContainer[node.idx])):
                    node.idx = i

        ans = []

        for q in wordsQuery:
            node = root

            for ch in q[::-1]:
                if ch not in node.child:
                    break
                node = node.child[ch]

            ans.append(node.idx)

        return ans
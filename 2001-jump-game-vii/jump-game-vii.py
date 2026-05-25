from collections import deque

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:

        n = len(s)

        q = deque([0])

        farthest = 0

        while q:

            start = q.popleft()

            left = max(start + minJump, farthest + 1)
            right = min(start + maxJump + 1, n)

            for y in range(left, right):

                if s[y] == '0':

                    if y == n - 1:
                        return True

                    q.append(y)

            farthest = start + maxJump

        return n == 1
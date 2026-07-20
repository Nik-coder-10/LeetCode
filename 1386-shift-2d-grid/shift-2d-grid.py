class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        k %= m * n
        ans = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                idx = (i * n + j + k) % (m * n)
                ans[idx // n][idx % n] = grid[i][j]

        return ans
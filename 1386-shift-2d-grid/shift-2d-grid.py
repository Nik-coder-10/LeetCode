class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        a = sum(grid, [])
        k %= len(a)
        a = a[-k:] + a[:-k]
        return [a[i:i+n] for i in range(0, len(a), n)]
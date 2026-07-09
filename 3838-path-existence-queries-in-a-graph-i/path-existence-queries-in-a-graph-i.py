class Solution:
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        p = list(range(n))

        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        for i in range(n - 1):
            if nums[i + 1] - nums[i] <= maxDiff:
                p[find(i)] = find(i + 1)

        return [find(u) == find(v) for u, v in queries]
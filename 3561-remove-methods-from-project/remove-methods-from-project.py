class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        for u, v in invocations:
            graph[u].append(v)

        suspicious = set()

        def dfs(u):
            suspicious.add(u)
            for v in graph[u]:
                if v not in suspicious:
                    dfs(v)

        dfs(k)

        for u, v in invocations:
            if u not in suspicious and v in suspicious:
                return list(range(n))

        return [i for i in range(n) if i not in suspicious]
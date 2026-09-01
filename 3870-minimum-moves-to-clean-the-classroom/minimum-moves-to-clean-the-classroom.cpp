class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0, cnt = 0;
        vector<vector<int>> litter(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int fullMask = (1 << cnt) - 1;

        vector vis(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    int ne = e - 1;

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X' || ne < 0)
                        continue;

                    int newMask = mask;

                    if (classroom[nr][nc] == 'L')
                        newMask |= 1 << litter[nr][nc];

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (vis[nr][nc][ne][newMask])
                        continue;

                    vis[nr][nc][ne][newMask] = true;
                    q.push({nr, nc, ne, newMask});
                }
            }

            moves++;
        }

        return -1;
    }
};
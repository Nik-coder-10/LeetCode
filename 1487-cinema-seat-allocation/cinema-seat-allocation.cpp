class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> rows;

        for (auto &x : reservedSeats)
            rows[x[0]].insert(x[1]);

        int ans = (n - rows.size()) * 2;

        for (auto &[r, seats] : rows) {
            bool left = 1, mid = 1, right = 1;

            for (int x = 2; x <= 5; x++)
                if (seats.count(x)) left = 0;

            for (int x = 4; x <= 7; x++)
                if (seats.count(x)) mid = 0;

            for (int x = 6; x <= 9; x++)
                if (seats.count(x)) right = 0;

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans++;
        }

        return ans;
    }
};
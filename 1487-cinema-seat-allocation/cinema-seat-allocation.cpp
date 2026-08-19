class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto &x : reservedSeats)
            mp[x[0]].insert(x[1]);

        int ans = (n - mp.size()) * 2;

        for (auto &[r, s] : mp) {
            bool left = true, mid = true, right = true;

            for (int i = 2; i <= 5; i++)
                left &= !s.count(i);

            for (int i = 4; i <= 7; i++)
                mid &= !s.count(i);

            for (int i = 6; i <= 9; i++)
                right &= !s.count(i);

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans++;
        }

        return ans;
    }
};
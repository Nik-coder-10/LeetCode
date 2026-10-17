class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int x : nums)
            a.push_back({digitSum(x), x});

        sort(a.begin(), a.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[i] = pos[nums[i]];

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || p[i] == i)
                continue;

            int len = 0, j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = p[j];
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};
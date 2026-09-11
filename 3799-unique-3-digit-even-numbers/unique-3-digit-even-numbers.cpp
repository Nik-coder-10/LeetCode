class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int x : digits)
            cnt[x]++;

        int ans = 0;

        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            int need[10] = {};
            need[a]++;
            need[b]++;
            need[c]++;

            bool ok = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > cnt[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans++;
        }

        return ans;
    }
};
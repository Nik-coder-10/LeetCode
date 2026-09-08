class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (i >= 1000)
                ans++;
        }

        return ans;
    }
};
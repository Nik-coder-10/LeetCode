class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long l = dfs(left);
        long long r = dfs(right);

        return comb[n - 1][left.size()] * l % MOD * r % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++)
                comb[i][j] = (comb[i - 1][j - 1] +
                              comb[i - 1][j]) % MOD;
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        std::vector<int> bitCount(30, 0);

        for (int x : nums) {
            for (int b = 0; b < 30; ++b) {
                if ((x >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        long long totalSum = 0;

        for (int i = 0; i < k; ++i) {
            long long val = 0;
            for (int b = 0; b < 30; ++b) {
                if (bitCount[b] > 0) {
                    val |= (1LL << b);
                    bitCount[b]--;
                }
            }
            totalSum = (totalSum + (val % MOD) * (val % MOD)) % MOD;
        }

        return totalSum;
    }
};
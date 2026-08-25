class Solution {
public:
    int solve(vector<int>& nums, int k, int x) {
        for (int n : nums) {
            if (n == x) {
                return solve(nums, k, x + k);
            }
        }

        return x;
    }

    int missingMultiple(vector<int>& nums, int k) {
        return solve(nums, k, k);
    }
};
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> special;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                special.push_back(nums[i - 1]);
        }

        for (int x : special)
            sum += x * x;

        return sum;
    }
};
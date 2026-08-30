class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0, maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        return min({
            right + 1,
            n - left,
            left + 1 + n - right
        });
    }
};
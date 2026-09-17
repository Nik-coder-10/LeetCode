class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n + 1, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target)
                sum -= arr[left++];

            best[right + 1] = best[right];

            if (sum == target) {
                int len = right - left + 1;

                if (best[left] != INF)
                    ans = min(ans, best[left] + len);

                best[right + 1] = min(best[right + 1], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
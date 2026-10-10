class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> d(n);
        long long total = 0;
        int mx = 0;

        long long k = (long long)k1 + k2;

        for(int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
            mx = max(mx, d[i]);
        }

        if(total <= k) return 0;

        int l = 0, r = mx;

        while(l < r) {
            int mid = l + (r - l) / 2;
            long long need = 0;

            for(int x : d)
                need += max(0, x - mid);

            if(need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        for(int i = 0; i < n; i++) {
            k -= max(0, d[i] - l);
            d[i] = min(d[i], l);
        }

        for(int i = 0; i < n && k > 0; i++) {
            if(d[i] == l) {
                d[i]--;
                k--;
            }
        }

        long long ans = 0;
        for(int x : d)
            ans += 1LL * x * x;

        return ans;
    }
};
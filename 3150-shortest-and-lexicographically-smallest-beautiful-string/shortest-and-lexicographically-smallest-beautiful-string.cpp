class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        int bestLeft = -1;
        int bestLen = n + 1;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            while (ones == k && s[left] == '0')
                left++;

            if (ones == k) {
                int len = right - left + 1;

                if (len < bestLen) {
                    bestLen = len;
                    bestLeft = left;
                }
                else if (len == bestLen) {
                    if (s.compare(left, len, s, bestLeft, bestLen) < 0)
                        bestLeft = left;
                }
            }
        }

        if (bestLeft == -1)
            return "";

        return s.substr(bestLeft, bestLen);
    }
};
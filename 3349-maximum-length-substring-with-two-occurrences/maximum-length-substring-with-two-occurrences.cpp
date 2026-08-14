class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {};
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'a']++;

            while (freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
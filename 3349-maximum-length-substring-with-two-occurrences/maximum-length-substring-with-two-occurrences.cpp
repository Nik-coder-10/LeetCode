class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int freq[26] = {};

            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;

                if (freq[s[j] - 'a'] > 2)
                    break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
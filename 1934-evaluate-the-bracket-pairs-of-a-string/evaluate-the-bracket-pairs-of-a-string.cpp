class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& x : knowledge)
            mp[x[0]] = x[1];

        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int j = i + 1;

                while (s[j] != ')')
                    j++;

                string key = s.substr(i + 1, j - i - 1);

                if (mp.count(key))
                    ans += mp[key];
                else
                    ans += '?';

                i = j;
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
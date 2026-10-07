class Solution {
public:
    unordered_set<string> ans;
    int n;

    void dfs(string& s, int i, int l, int r, int open, int close, string& cur) {
        if(i == n) {
            if(l == 0 && r == 0)
                ans.insert(cur);
            return;
        }

        if(n - i < l + r || open < close)
            return;

        if(s[i] == '(' && l > 0)
            dfs(s, i + 1, l - 1, r, open, close, cur);

        if(s[i] == ')' && r > 0)
            dfs(s, i + 1, l, r - 1, open, close, cur);

        cur.push_back(s[i]);

        if(s[i] == '(')
            dfs(s, i + 1, l, r, open + 1, close, cur);
        else if(s[i] == ')')
            dfs(s, i + 1, l, r, open, close + 1, cur);
        else
            dfs(s, i + 1, l, r, open, close, cur);

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        int l = 0, r = 0;

        for(char c : s) {
            if(c == '(') {
                l++;
            } else if(c == ')') {
                if(l > 0)
                    l--;
                else
                    r++;
            }
        }

        string cur;
        dfs(s, 0, l, r, 0, 0, cur);

        return vector<string>(ans.begin(), ans.end());
    }
};
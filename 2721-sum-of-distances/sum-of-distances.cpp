class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for (auto& [value, pos] : mp) {
            long long prefix = 0;

            for (int i = 0; i < pos.size(); i++) {
                ans[pos[i]] += (long long)pos[i] * i - prefix;
                prefix += pos[i];
            }

            long long suffix = 0;

            for (int i = pos.size() - 1; i >= 0; i--) {
                ans[pos[i]] += suffix - (long long)pos[i] * (pos.size() - 1 - i);
                suffix += pos[i];
            }
        }

        return ans;
    }
};
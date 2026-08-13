class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {};
        int ans = 0;

        for (int x : nums) {
            ans += freq[x];
            freq[x]++;
        }

        return ans;
    }
};
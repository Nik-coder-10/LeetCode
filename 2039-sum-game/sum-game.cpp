class Solution {
public:
    bool sumGame(string num) {
        double diff = 0;

        for (int i = 0; i < num.size() / 2; i++)
            diff += num[i] == '?' ? 4.5 : num[i] - '0';

        for (int i = num.size() / 2; i < num.size(); i++)
            diff -= num[i] == '?' ? 4.5 : num[i] - '0';

        return diff != 0;
    }
};
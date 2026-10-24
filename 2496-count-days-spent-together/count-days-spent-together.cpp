class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3));
            for (int i = 1; i < month; i++)
                day += days[i];
            return day;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};
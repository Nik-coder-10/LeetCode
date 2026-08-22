class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int x = n;

        while (x) {
            int d = x % 10;
            sum += d;
            product *= d;
            x /= 10;
        }

        return n % (sum + product) == 0;
    }
};
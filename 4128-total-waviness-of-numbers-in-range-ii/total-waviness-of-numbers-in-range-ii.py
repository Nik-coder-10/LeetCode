class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:

        def count_upto(limit):
            if limit < 100:
                return 0

            def solve(bound):
                memo = {}

                def dp(pos, tight, prev2, prev1):
                    if pos == len(bound):
                        return (1, 0)

                    state = (pos, tight, prev2, prev1)
                    if state in memo:
                        return memo[state]

                    max_digit = int(bound[pos]) if tight else 9
                    total_count = 0
                    total_waviness = 0

                    for digit in range(max_digit + 1):
                        count, waviness = dp(
                            pos + 1,
                            tight and digit == max_digit,
                            prev1,
                            digit
                        )

                        add = 0
                        if prev2 != 10:
                            if (prev2 < prev1 > digit) or (prev2 > prev1 < digit):
                                add = 1

                        total_count += count
                        total_waviness += waviness + count * add

                    memo[state] = (total_count, total_waviness)
                    return memo[state]

                answer = 0
                first_digit = int(bound[0])

                for digit in range(1, first_digit + 1):
                    answer += dp(
                        1,
                        digit == first_digit,
                        10,
                        digit
                    )[1]

                return answer

            s = str(limit)
            result = 0

            for length in range(3, len(s)):
                result += solve("9" * length)

            result += solve(s)
            return result

        return count_upto(num2) - count_upto(num1 - 1)
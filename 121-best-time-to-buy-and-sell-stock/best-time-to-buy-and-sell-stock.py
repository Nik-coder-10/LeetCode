class Solution:
    def maxProfit(self, prices):
        buy = prices[0]
        profit = 0

        for price in prices:
            if price < buy:
                buy = price

            if price - buy > profit:
                profit = price - buy

        return profit
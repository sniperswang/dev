"""
Given a non-negative integer n, count all numbers with unique digits, x, where 0 <= x <= 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 <= x <= 100, excluding [11,22,33,44,55,66,77,88,99])

"""
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """

        if (n == 0):
          return 1

        if (n == 1):
          return 10

        base = 9
        ans = 10
        for i in range (2, n+1):
            if (n > 10):
              break
            base = base*(9-i+2)
            ans += base

        return ans
          
            
          
s = Solution()
print s.countNumbersWithUniqueDigits(2)


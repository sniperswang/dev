"""
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

"""

class Solution(object):
    def isPerfectSquare(self, num):
      """
      :type num: int
      :rtype: bool
      """
      i = 0;

      while ( i*i <= num ):
        if (i*i == num):
          return True
        i+=1

      return False


s = Solution()
print s.isPerfectSquare(14)


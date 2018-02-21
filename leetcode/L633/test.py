"""
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
"""
import math

class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        b = int(math.sqrt(c))
        a = 0;
        while (a <= b):
          if (a*a + b*b) == c:
            return True
          if (a*a + b*b ) < c:
              a +=1 
              continue
          else:
              b -=1
              continue
          
        return False

s = Solution()
print s.judgeSquareSum(3)


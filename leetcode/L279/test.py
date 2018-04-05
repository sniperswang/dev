"""
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

"""

import math
from sets import Set

class Solution(object):

    def numSquaresX(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.steps  = [n]*(n+1)
        self.steps[0] = 0
        self.steps[1] = 1


        for i in xrange(2,n+1):
            j = 1
            while (j*j <= i):
              self.steps[i] = min(self.steps[i], self.steps[i-j*j] +1)
              j +=1
              
        
        return self.steps[n]
      
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
          return n;
        lst = []

        i = 1;
        while i*i < n+1:
          lst.append(i*i);
          if i*i == n:
            return 1
          i += 1

        cnt = 0;
        checkList = {n}
        while checkList:
          temp = set()
          cnt += 1
          for x in checkList:
            for y in lst:
              if (x == y):
                return cnt 
              if ( y < x):
                temp.add(x-y)
          checkList = temp 

        return cnt
      

s = Solution()
print s.numSquares(6)
